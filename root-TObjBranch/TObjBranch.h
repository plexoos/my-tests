#ifndef TObjBranch_h
#define TObjBranch_h

/**
 * A header-only interface to associate ROOT objects with ROOT branches.
 *
 * \author Dmitri Smirnov <dmixsmi@gmail.com>
 * \date 6 March, 2018
 * \version 1.0
 */

#include <set>
#include <utility>
#include <iterator>

#include "TBranch.h"
#include "TObject.h"
#include "TTree.h"
#include "TClonesArray.h"


template <class TObject_t>
class TTypedIter : public TIter
{
   static_assert(std::is_base_of<TObject, TObject_t>::value, "TObject_t type must inherit from TObject");

   TTypedIter() = default;

public:

   TTypedIter(const TIter &iter) : TIter(iter) {}

   TObject_t& operator()() { return *static_cast<TObject_t *>(TIter::Next()); }
   TObject_t& Next() { return *static_cast<TObject_t *>(TIter::Next()); }
   TObject_t& operator*() const { return *static_cast<TObject_t *>(TIter::operator*()); }
};




class TBranchI
{
public:

   virtual void ReadFrom(TTree& tree) = 0;

   virtual void WriteTo(TTree& tree) = 0;

   virtual void Clear() = 0;

   virtual int GetSize() const = 0;

   virtual TObject& GetObj(int index = 0) const = 0;

};



template<typename TObject_t>
class TBranchT : public TBranchI
{
public:

   using TObjectType = TObject_t;

   virtual void ReadFrom(TTree& tree)
   {
     tree.SetBranchAddress<TObject_t>( mBranchName.c_str(), &mObjPtr );
   }

   /// Branch is created on the tree only if it does not already exist.
   /// Otherwise it will be silently ignored
   virtual void WriteTo(TTree& tree)
   {
     if ( !tree.GetBranch(mBranchName.c_str()) )
     {
        tree.Branch(mBranchName.c_str(), &mObj, mBufferSize, mSplit);
     }
   }

   std::string GetName() const { return mBranchName; }

protected:

   TBranchT(std::string branch_name) :
     mBranchName(branch_name),
     mBufferSize(65536),
     mSplit(99),
     mObj(),
     mObjPtr(&mObj)
   { }

   std::string  mBranchName;

   int  mBufferSize;

   int  mSplit;

   TObject_t  mObj;

private:

  /// A dummy pointer to the internal object of a type deriving from TObject
  TObject_t*  mObjPtr;

};



template<typename TObject_t>
class TObjBranch : public TBranchT<TObject_t>
{
public:

   TObjBranch(std::string branch_name) : TBranchT<TObject_t>(branch_name)
   { }

   virtual void Clear()
   { }

   virtual TObject_t& GetObj(int index = 0) const
   {
      return this->mObj;
   }

   virtual int GetSize() const
   {
      return 1;
   }

};



template<typename TObject_t>
class TCABranch : public TBranchT<TClonesArray>
{
public:

  using TObjectType = TObject_t;

  TCABranch(std::string branch_name, int initial_size = 100) : TBranchT<TClonesArray>(branch_name)
  {
     mObj.SetClass(TObject_t().ClassName(), initial_size);
  }


  /**
   * Removes all elements from the internal container mObj of type TClonesArray.
   *
   * For details see documentation for TClonesArray::Clear() at
   * https://root.cern.ch/doc/master/classTClonesArray.html
   *
   * "... TClonesArray allows you to "reuse" the same portion of memory ...
   * Every time the memory of the TClonesArray has to be reused, the Clear()
   * method is used. ... "
   */
  virtual void Clear()
  {
     mObj.Clear();
  }

  virtual TObject_t& GetObj(int index = 0) const
  {
     return static_cast<TObject_t&>( *mObj.UncheckedAt(index) );
  }

  TClonesArray& GetTCA() const
  {
     return mObj;
  }

  virtual int GetSize() const
  {
     return mObj.GetEntries();
  }


  template<typename... Args>
  std::pair<TObject_t*, int>  AddObj(Args&&... args)
  {
     int last_index = mObj.GetEntries();

     TObject_t* obj = new( mObj[last_index] )  TObject_t(std::forward<Args>(args)...);

     return std::make_pair(obj, last_index);
  }


  const TTypedIter<TObject_t> begin() const
  {
    return mObj.begin();
  }


  const TTypedIter<TObject_t> end() const
  {
     return mObj.end();
  }

};


/**
 * A set of `TObjBranch`es
 */
class TObjTree
{
public:

   TObjTree(TTree& tree) : mTree(tree), mBranches()
   { }


   void ReadFrom(TTree& tree)
   {
      for (auto branch : mBranches)
         branch->ReadFrom(tree);
   }


   void WriteTo(TTree& tree)
   {
      for (auto branch : mBranches)
         branch->WriteTo(tree);
   }


   template<typename TObject_t>
   TCABranch<TObject_t>& AttachTCA( std::string branch_name )
   {
      auto tca_branch = new TCABranch<TObject_t>(branch_name);
      auto result = mBranches.insert( tca_branch );

      return *tca_branch;
   }


   template<typename TObject_t>
   TCABranch<TObject_t>& ReadTCA( std::string branch_name )
   {
      auto& tca_branch = AttachTCA<TObject_t>(branch_name);
      tca_branch.ReadFrom(mTree);
      return tca_branch;
   }


   template<typename TObject_t>
   TCABranch<TObject_t>& WriteTCA( std::string branch_name )
   {
      auto& tca_branch = AttachTCA<TObject_t>(branch_name);
      tca_branch.WriteTo(mTree);
      return tca_branch;
   }

private:

   ///
   TTree&  mTree;

   std::set< TBranchI* >  mBranches;
};

#endif
