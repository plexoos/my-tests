#include <algorithm>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <random>


struct Item
{
  int level1;
  int level2;
  int value;

  friend std::ostream& operator<<(std::ostream& os, const Item& item)
  {
    os << std::setw(5) << item.value;
    return os;
  }
};


/**
 * A collection of Items packed in a multidimensional array of vectors:
 *
 * std::vector<Item> myvec[max_level1][max_level2];
 *
 */
template<int MAX_L1, int MAX_L2>
struct Collection
{
  static const int max_level1 = MAX_L1;
  static const int max_level2 = MAX_L2;

  using vector_t = std::vector<Item>;
  using level2_t = vector_t[max_level2];
  using level1_t = level2_t[max_level1];

  std::vector<Item> myvec[max_level1][max_level2];


  Collection()
  {
    std::random_device rd;
    std::mt19937 rengine(rd());
    //std::mt19937 rengine(12345);
    std::uniform_int_distribution<> rmaxlen(0, 10);
    std::uniform_int_distribution<> rlength(0, rmaxlen(rengine));
    std::uniform_int_distribution<> rdistri(10, 99);

    for (int l1 = 0; l1 < max_level1; ++l1)
      for (int l2 = 0; l2 < max_level2; ++l2)
        for (int i = 0; i < rlength(rengine); ++i)
          myvec[l1][l2].push_back( {l1, l2, rdistri(rengine)} );
  }

  friend std::ostream& operator<<(std::ostream& os, const Collection& c)
  {
    for (int l1 = 0; l1 < c.max_level1; ++l1)
      for (int l2 = 0; l2 < c.max_level2; ++l2)
      {
        os << "[" << std::setw(5) << l1 << "][" << std::setw(5) << l2 << "]: ";
        const vector_t& v = c.myvec[l1][l2];

        if (v.empty()) os << "empty";
        else
          for (const Item& item : v) os << item;

        os << std::endl;
      }
    return os;
  }


  /// A flat iterator over a Collection of Items
  class ItemIter : public std::iterator<std::input_iterator_tag, Item>
  {
  public:

    static ItemIter begin(Collection& c)
    {
      // Skip to the first non-empty vector
      for (int l1 = 0; l1 < c.max_level1; ++l1)
        for (int l2 = 0; l2 < c.max_level2; ++l2)
          if (!c.myvec[l1][l2].empty()) return ItemIter(c, l1, l2);
      return end(c);
    }

    static ItemIter end(Collection& c)
    {
      return ItemIter(c, c.max_level1);
    }

    ItemIter() = default;

    // ++prefix operator
    ItemIter& operator++()
    {
      ++iItem;

      // Reset counters when range maximum reached (next outer nested level)
      vector_t& currVector = coll.myvec[iLevel1][iLevel2];
      if (iItem >= currVector.size()) {
        ++iLevel2;
        iItem = 0;
      }

      // Reset counters when range maximum reached (next outer nested level)
      if (iLevel2 >= max_level2) {
        ++iLevel1;
        iLevel2 = 0;
        iItem = 0;
      }

      // Skip next vector if empty and increase indices
      if (*this != end(coll)) {
        vector_t& nextVector = coll.myvec[iLevel1][iLevel2];
        if (nextVector.empty()) {
          iItem = 0;
          (*this).operator++();
        }
      }

      return *this;
    }

    bool operator==(const ItemIter &other) const
    {
      return &other.coll == &coll && other.iLevel1 == iLevel1 && other.iLevel2 == iLevel2 && other.iItem == iItem;
    }

    bool operator!=(const ItemIter &other) const
    {
      return !(*this == other);
    }

    Item& operator*()
    {
      return coll.myvec[iLevel1][iLevel2][iItem];
    }

    const Item& operator*() const
    {
      return *(*this);
    }

    friend std::ostream& operator<<(std::ostream& os, const ItemIter& ii)
    {
      os << std::setw(5) << ii.iLevel1
         << std::setw(5) << ii.iLevel2
         << std::setw(5) << ii.iItem;
      return os;
    }

  private:

    ItemIter(Collection& c, int l1=0, int l2=0) : coll(c), iLevel1(l1), iLevel2(l2), iItem(0) {}

    Collection& coll;

    std::size_t iLevel1 = 0;
    std::size_t iLevel2 = 0;
    std::size_t iItem = 0;
  };

  ItemIter begin() { return ItemIter::begin(*this); }
  ItemIter end()   { return ItemIter::end(*this); }
};


int main(int argc, char **argv)
{
  // Define dimenstions of 2D array
  using MyCollection = Collection<4, 3>;
  // Fill collection with random numbers
  MyCollection mycoll;
  std::cout << mycoll;

  MyCollection::ItemIter mybeg = mycoll.begin();
  MyCollection::ItemIter myend = mycoll.end();

  std::cout << "Collection::begin(): " << mybeg << "\n";
  std::cout << "Collection::end():   " << myend << "\n";

  int i = 0;
  for (const Item& item : mycoll) {
    std::cout << std::setw(5) << i << ": " << item << "\n";
    ++i;
  }

  return EXIT_SUCCESS;
}
