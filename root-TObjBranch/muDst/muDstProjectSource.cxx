namespace std {}
using namespace std;
#include "muDstProjectHeaders.h"

#include "muDstLinkDef.h"

#include "muDstProjectDict.cxx"

struct DeleteObjectFunctor {
   template <typename T>
   void operator()(const T *ptr) const {
      delete ptr;
   }
   template <typename T, typename Q>
   void operator()(const std::pair<T,Q> &) const {
      // Do nothing
   }
   template <typename T, typename Q>
   void operator()(const std::pair<T,Q*> &ptr) const {
      delete ptr.second;
   }
   template <typename T, typename Q>
   void operator()(const std::pair<T*,Q> &ptr) const {
      delete ptr.first;
   }
   template <typename T, typename Q>
   void operator()(const std::pair<T*,Q*> &ptr) const {
      delete ptr.first;
      delete ptr.second;
   }
};

#ifndef StObject_cxx
#define StObject_cxx
StObject::StObject() {
}
StObject::StObject(const StObject & rhs)
   : TObject(const_cast<StObject &>( rhs ))
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StObject::~StObject() {
}
#endif // StObject_cxx

#ifndef StV0MuDst_cxx
#define StV0MuDst_cxx
StV0MuDst::StV0MuDst() {
}
StV0MuDst::StV0MuDst(const StV0MuDst & rhs)
   : StStrangeMuDst(const_cast<StV0MuDst &>( rhs ))
   , StV0I(const_cast<StV0MuDst &>( rhs ))
   , mDecayVertexV0X(const_cast<StV0MuDst &>( rhs ).mDecayVertexV0X)
   , mDecayVertexV0Y(const_cast<StV0MuDst &>( rhs ).mDecayVertexV0Y)
   , mDecayVertexV0Z(const_cast<StV0MuDst &>( rhs ).mDecayVertexV0Z)
   , mDcaV0Daughters(const_cast<StV0MuDst &>( rhs ).mDcaV0Daughters)
   , mDcaV0ToPrimVertex(const_cast<StV0MuDst &>( rhs ).mDcaV0ToPrimVertex)
   , mDcaPosToPrimVertex(const_cast<StV0MuDst &>( rhs ).mDcaPosToPrimVertex)
   , mDcaNegToPrimVertex(const_cast<StV0MuDst &>( rhs ).mDcaNegToPrimVertex)
   , mMomPosX(const_cast<StV0MuDst &>( rhs ).mMomPosX)
   , mMomPosY(const_cast<StV0MuDst &>( rhs ).mMomPosY)
   , mMomPosZ(const_cast<StV0MuDst &>( rhs ).mMomPosZ)
   , mMomNegX(const_cast<StV0MuDst &>( rhs ).mMomNegX)
   , mMomNegY(const_cast<StV0MuDst &>( rhs ).mMomNegY)
   , mMomNegZ(const_cast<StV0MuDst &>( rhs ).mMomNegZ)
   , mKeyPos(const_cast<StV0MuDst &>( rhs ).mKeyPos)
   , mKeyNeg(const_cast<StV0MuDst &>( rhs ).mKeyNeg)
   , mTopologyMapPos(const_cast<StV0MuDst &>( rhs ).mTopologyMapPos)
   , mTopologyMapNeg(const_cast<StV0MuDst &>( rhs ).mTopologyMapNeg)
   , mChi2V0(const_cast<StV0MuDst &>( rhs ).mChi2V0)
   , mClV0(const_cast<StV0MuDst &>( rhs ).mClV0)
   , mChi2Pos(const_cast<StV0MuDst &>( rhs ).mChi2Pos)
   , mClPos(const_cast<StV0MuDst &>( rhs ).mClPos)
   , mChi2Neg(const_cast<StV0MuDst &>( rhs ).mChi2Neg)
   , mClNeg(const_cast<StV0MuDst &>( rhs ).mClNeg)
   , mDedxPos(const_cast<StV0MuDst &>( rhs ).mDedxPos)
   , mDedxNeg(const_cast<StV0MuDst &>( rhs ).mDedxNeg)
   , mErrDedxPos(const_cast<StV0MuDst &>( rhs ).mErrDedxPos)
   , mErrDedxNeg(const_cast<StV0MuDst &>( rhs ).mErrDedxNeg)
   , mNumDedxPos(const_cast<StV0MuDst &>( rhs ).mNumDedxPos)
   , mNumDedxNeg(const_cast<StV0MuDst &>( rhs ).mNumDedxNeg)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StV0MuDst::~StV0MuDst() {
}
#endif // StV0MuDst_cxx

#ifndef StStrangeMuDst_cxx
#define StStrangeMuDst_cxx
StStrangeMuDst::StStrangeMuDst() {
}
StStrangeMuDst::StStrangeMuDst(const StStrangeMuDst & rhs)
   : TObject(const_cast<StStrangeMuDst &>( rhs ))
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StStrangeMuDst::~StStrangeMuDst() {
}
#endif // StStrangeMuDst_cxx

#ifndef StV0I_cxx
#define StV0I_cxx
StV0I::StV0I() {
}
StV0I::StV0I(const StV0I & rhs)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StV0I::~StV0I() {
}
#endif // StV0I_cxx

#ifndef StTrackTopologyMap_cxx
#define StTrackTopologyMap_cxx
StTrackTopologyMap::StTrackTopologyMap() {
}
StTrackTopologyMap::StTrackTopologyMap(const StTrackTopologyMap & rhs)
   : StObject(const_cast<StTrackTopologyMap &>( rhs ))
   , mMap0(const_cast<StTrackTopologyMap &>( rhs ).mMap0)
   , mMap1(const_cast<StTrackTopologyMap &>( rhs ).mMap1)
   , mMap_iTpc(const_cast<StTrackTopologyMap &>( rhs ).mMap_iTpc)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StTrackTopologyMap::~StTrackTopologyMap() {
}
#endif // StTrackTopologyMap_cxx

#ifndef StXiMuDst_cxx
#define StXiMuDst_cxx
StXiMuDst::StXiMuDst() {
}
StXiMuDst::StXiMuDst(const StXiMuDst & rhs)
   : StV0MuDst(const_cast<StXiMuDst &>( rhs ))
   , StXiI(const_cast<StXiMuDst &>( rhs ))
   , mCharge(const_cast<StXiMuDst &>( rhs ).mCharge)
   , mDecayVertexXiX(const_cast<StXiMuDst &>( rhs ).mDecayVertexXiX)
   , mDecayVertexXiY(const_cast<StXiMuDst &>( rhs ).mDecayVertexXiY)
   , mDecayVertexXiZ(const_cast<StXiMuDst &>( rhs ).mDecayVertexXiZ)
   , mDcaXiDaughters(const_cast<StXiMuDst &>( rhs ).mDcaXiDaughters)
   , mDcaBachelorToPrimVertex(const_cast<StXiMuDst &>( rhs ).mDcaBachelorToPrimVertex)
   , mDcaXiToPrimVertex(const_cast<StXiMuDst &>( rhs ).mDcaXiToPrimVertex)
   , mMomBachelorX(const_cast<StXiMuDst &>( rhs ).mMomBachelorX)
   , mMomBachelorY(const_cast<StXiMuDst &>( rhs ).mMomBachelorY)
   , mMomBachelorZ(const_cast<StXiMuDst &>( rhs ).mMomBachelorZ)
   , mKeyBachelor(const_cast<StXiMuDst &>( rhs ).mKeyBachelor)
   , mTopologyMapBachelor(const_cast<StXiMuDst &>( rhs ).mTopologyMapBachelor)
   , mChi2Xi(const_cast<StXiMuDst &>( rhs ).mChi2Xi)
   , mClXi(const_cast<StXiMuDst &>( rhs ).mClXi)
   , mChi2Bachelor(const_cast<StXiMuDst &>( rhs ).mChi2Bachelor)
   , mClBachelor(const_cast<StXiMuDst &>( rhs ).mClBachelor)
   , mDedxBachelor(const_cast<StXiMuDst &>( rhs ).mDedxBachelor)
   , mErrDedxBachelor(const_cast<StXiMuDst &>( rhs ).mErrDedxBachelor)
   , mNumDedxBachelor(const_cast<StXiMuDst &>( rhs ).mNumDedxBachelor)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StXiMuDst::~StXiMuDst() {
}
#endif // StXiMuDst_cxx

#ifndef StXiI_cxx
#define StXiI_cxx
StXiI::StXiI() {
}
StXiI::StXiI(const StXiI & rhs)
   : StV0I(const_cast<StXiI &>( rhs ))
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StXiI::~StXiI() {
}
#endif // StXiI_cxx

#ifndef StKinkMuDst_cxx
#define StKinkMuDst_cxx
StKinkMuDst::StKinkMuDst() {
}
StKinkMuDst::StKinkMuDst(const StKinkMuDst & rhs)
   : StKinkBase(const_cast<StKinkMuDst &>( rhs ))
   , mDcaParentDaughter(const_cast<StKinkMuDst &>( rhs ).mDcaParentDaughter)
   , mDcaDaughterPrimaryVertex(const_cast<StKinkMuDst &>( rhs ).mDcaDaughterPrimaryVertex)
   , mDcaParentPrimaryVertex(const_cast<StKinkMuDst &>( rhs ).mDcaParentPrimaryVertex)
   , mHitDistanceParentDaughter(const_cast<StKinkMuDst &>( rhs ).mHitDistanceParentDaughter)
   , mHitDistanceParentVertex(const_cast<StKinkMuDst &>( rhs ).mHitDistanceParentVertex)
   , mMinDeltaEnergy(const_cast<StKinkMuDst &>( rhs ).mMinDeltaEnergy)
   , mDecayAngle(const_cast<StKinkMuDst &>( rhs ).mDecayAngle)
   , mParentMomentum(const_cast<StKinkMuDst &>( rhs ).mParentMomentum)
   , mParentPrimMomentum(const_cast<StKinkMuDst &>( rhs ).mParentPrimMomentum)
   , mParentCharge(const_cast<StKinkMuDst &>( rhs ).mParentCharge)
   , mDaughterMomentum(const_cast<StKinkMuDst &>( rhs ).mDaughterMomentum)
   , mDaughterCharge(const_cast<StKinkMuDst &>( rhs ).mDaughterCharge)
   , mDecayLength(const_cast<StKinkMuDst &>( rhs ).mDecayLength)
   , mTransverseMomentum(const_cast<StKinkMuDst &>( rhs ).mTransverseMomentum)
   , mTransverseMassKaon(const_cast<StKinkMuDst &>( rhs ).mTransverseMassKaon)
   , mTransverseMassPion(const_cast<StKinkMuDst &>( rhs ).mTransverseMassPion)
   , mRapidityKaon(const_cast<StKinkMuDst &>( rhs ).mRapidityKaon)
   , mRapidityPion(const_cast<StKinkMuDst &>( rhs ).mRapidityPion)
   , mChi2Kink(const_cast<StKinkMuDst &>( rhs ).mChi2Kink)
   , mClKink(const_cast<StKinkMuDst &>( rhs ).mClKink)
   , mChi2Parent(const_cast<StKinkMuDst &>( rhs ).mChi2Parent)
   , mClParent(const_cast<StKinkMuDst &>( rhs ).mClParent)
   , mChi2Daughter(const_cast<StKinkMuDst &>( rhs ).mChi2Daughter)
   , mClDaughter(const_cast<StKinkMuDst &>( rhs ).mClDaughter)
   , mDedxParent(const_cast<StKinkMuDst &>( rhs ).mDedxParent)
   , mDedxDaughter(const_cast<StKinkMuDst &>( rhs ).mDedxDaughter)
   , mErrDedxParent(const_cast<StKinkMuDst &>( rhs ).mErrDedxParent)
   , mErrDedxDaughter(const_cast<StKinkMuDst &>( rhs ).mErrDedxDaughter)
   , mNumDedxParent(const_cast<StKinkMuDst &>( rhs ).mNumDedxParent)
   , mNumDedxDaughter(const_cast<StKinkMuDst &>( rhs ).mNumDedxDaughter)
   , mKeyParent(const_cast<StKinkMuDst &>( rhs ).mKeyParent)
   , mKeyDaughter(const_cast<StKinkMuDst &>( rhs ).mKeyDaughter)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StKinkMuDst::~StKinkMuDst() {
}
#endif // StKinkMuDst_cxx

#ifndef StKinkBase_cxx
#define StKinkBase_cxx
StKinkBase::StKinkBase() {
}
StKinkBase::StKinkBase(const StKinkBase & rhs)
   : StStrangeMuDst(const_cast<StKinkBase &>( rhs ))
   , StKinkI(const_cast<StKinkBase &>( rhs ))
   , mParentGeantId(const_cast<StKinkBase &>( rhs ).mParentGeantId)
   , mDaughterGeantId(const_cast<StKinkBase &>( rhs ).mDaughterGeantId)
   , mParentMomentumX(const_cast<StKinkBase &>( rhs ).mParentMomentumX)
   , mParentMomentumY(const_cast<StKinkBase &>( rhs ).mParentMomentumY)
   , mParentMomentumZ(const_cast<StKinkBase &>( rhs ).mParentMomentumZ)
   , mParentPrimMomentumX(const_cast<StKinkBase &>( rhs ).mParentPrimMomentumX)
   , mParentPrimMomentumY(const_cast<StKinkBase &>( rhs ).mParentPrimMomentumY)
   , mParentPrimMomentumZ(const_cast<StKinkBase &>( rhs ).mParentPrimMomentumZ)
   , mDaughterMomentumX(const_cast<StKinkBase &>( rhs ).mDaughterMomentumX)
   , mDaughterMomentumY(const_cast<StKinkBase &>( rhs ).mDaughterMomentumY)
   , mDaughterMomentumZ(const_cast<StKinkBase &>( rhs ).mDaughterMomentumZ)
   , mPositionX(const_cast<StKinkBase &>( rhs ).mPositionX)
   , mPositionY(const_cast<StKinkBase &>( rhs ).mPositionY)
   , mPositionZ(const_cast<StKinkBase &>( rhs ).mPositionZ)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StKinkBase::~StKinkBase() {
}
#endif // StKinkBase_cxx

#ifndef StKinkI_cxx
#define StKinkI_cxx
StKinkI::StKinkI() {
}
StKinkI::StKinkI(const StKinkI & rhs)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StKinkI::~StKinkI() {
}
#endif // StKinkI_cxx

#ifndef StStrangeEvMuDst_cxx
#define StStrangeEvMuDst_cxx
StStrangeEvMuDst::StStrangeEvMuDst() {
}
StStrangeEvMuDst::StStrangeEvMuDst(const StStrangeEvMuDst & rhs)
   : StStrangeMuDst(const_cast<StStrangeEvMuDst &>( rhs ))
   , mRun(const_cast<StStrangeEvMuDst &>( rhs ).mRun)
   , mEvent(const_cast<StStrangeEvMuDst &>( rhs ).mEvent)
   , mPrimaryVertexX(const_cast<StStrangeEvMuDst &>( rhs ).mPrimaryVertexX)
   , mPrimaryVertexY(const_cast<StStrangeEvMuDst &>( rhs ).mPrimaryVertexY)
   , mPrimaryVertexZ(const_cast<StStrangeEvMuDst &>( rhs ).mPrimaryVertexZ)
   , mGlobalTracks(const_cast<StStrangeEvMuDst &>( rhs ).mGlobalTracks)
   , mPrimaryTracks(const_cast<StStrangeEvMuDst &>( rhs ).mPrimaryTracks)
   , mPrimaryNegTracks(const_cast<StStrangeEvMuDst &>( rhs ).mPrimaryNegTracks)
   , mMagneticField(const_cast<StStrangeEvMuDst &>( rhs ).mMagneticField)
   , mL0TriggerWord(const_cast<StStrangeEvMuDst &>( rhs ).mL0TriggerWord)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StStrangeEvMuDst::~StStrangeEvMuDst() {
}
#endif // StStrangeEvMuDst_cxx

#ifndef StThreeVector_float__cxx
#define StThreeVector_float__cxx
StThreeVector<float>::StThreeVector() {
}
StThreeVector<float>::StThreeVector(const StThreeVector & rhs)
   : mX1(const_cast<StThreeVector &>( rhs ).mX1)
   , mX2(const_cast<StThreeVector &>( rhs ).mX2)
   , mX3(const_cast<StThreeVector &>( rhs ).mX3)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StThreeVector<float>::~StThreeVector() {
}
#endif // StThreeVector_float__cxx

#ifndef StMuEvent_cxx
#define StMuEvent_cxx
StMuEvent::StMuEvent() {
   mTriggerData = 0;
}
StMuEvent::StMuEvent(const StMuEvent & rhs)
   : TObject(const_cast<StMuEvent &>( rhs ))
   , mRunInfo(const_cast<StMuEvent &>( rhs ).mRunInfo)
   , mEventInfo(const_cast<StMuEvent &>( rhs ).mEventInfo)
   , mEventSummary(const_cast<StMuEvent &>( rhs ).mEventSummary)
   , mVpdTriggerDetector(const_cast<StMuEvent &>( rhs ).mVpdTriggerDetector)
   , mMtdTriggerDetector(const_cast<StMuEvent &>( rhs ).mMtdTriggerDetector)
   , mCtbTriggerDetector(const_cast<StMuEvent &>( rhs ).mCtbTriggerDetector)
   , mZdcTriggerDetector(const_cast<StMuEvent &>( rhs ).mZdcTriggerDetector)
   , mBbcTriggerDetector(const_cast<StMuEvent &>( rhs ).mBbcTriggerDetector)
   , mEmcTriggerDetector(const_cast<StMuEvent &>( rhs ).mEmcTriggerDetector)
   , mFpdTriggerDetector(const_cast<StMuEvent &>( rhs ).mFpdTriggerDetector)
   , mFmsTriggerDetector(const_cast<StMuEvent &>( rhs ).mFmsTriggerDetector)
   , mFpdCollection(const_cast<StMuEvent &>( rhs ).mFpdCollection)
   , mL0Trigger(const_cast<StMuEvent &>( rhs ).mL0Trigger)
   , mL3EventSummary(const_cast<StMuEvent &>( rhs ).mL3EventSummary)
   , mTriggerIdCollection(const_cast<StMuEvent &>( rhs ).mTriggerIdCollection)
   , mTriggerData(const_cast<StMuEvent &>( rhs ).mTriggerData)
   , mRefMultPos(const_cast<StMuEvent &>( rhs ).mRefMultPos)
   , mRefMultNeg(const_cast<StMuEvent &>( rhs ).mRefMultNeg)
   , mRefMultFtpcEast(const_cast<StMuEvent &>( rhs ).mRefMultFtpcEast)
   , mRefMultFtpcWest(const_cast<StMuEvent &>( rhs ).mRefMultFtpcWest)
   , mPrimaryVertexError(const_cast<StMuEvent &>( rhs ).mPrimaryVertexError)
   , mL2Result(const_cast<StMuEvent &>( rhs ).mL2Result)
   , mVpdEast(const_cast<StMuEvent &>( rhs ).mVpdEast)
   , mVpdWest(const_cast<StMuEvent &>( rhs ).mVpdWest)
   , mVpdTstart(const_cast<StMuEvent &>( rhs ).mVpdTstart)
   , mVpdTdiff(const_cast<StMuEvent &>( rhs ).mVpdTdiff)
   , mVpdVz(const_cast<StMuEvent &>( rhs ).mVpdVz)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   StMuEvent &modrhs = const_cast<StMuEvent &>( rhs );
   modrhs.mTriggerData = 0;
   for (Int_t i=0;i<2;i++) mReactionPlane[i] = rhs.mReactionPlane[i];
   for (Int_t i=0;i<2;i++) mReactionPlanePtWgt[i] = rhs.mReactionPlanePtWgt[i];
   for (Int_t i=0;i<4;i++) mNHitsHFT[i] = rhs.mNHitsHFT[i];
}
StMuEvent::~StMuEvent() {
   delete mTriggerData;   mTriggerData = 0;
}
#endif // StMuEvent_cxx

#ifndef StRunInfo_cxx
#define StRunInfo_cxx
StRunInfo::StRunInfo() {
}
StRunInfo::StRunInfo(const StRunInfo & rhs)
   : StObject(const_cast<StRunInfo &>( rhs ))
   , mRunId(const_cast<StRunInfo &>( rhs ).mRunId)
   , mProductionTime(const_cast<StRunInfo &>( rhs ).mProductionTime)
   , mProductionVersion(const_cast<StRunInfo &>( rhs ).mProductionVersion)
   , mCenterOfMassEnergy(const_cast<StRunInfo &>( rhs ).mCenterOfMassEnergy)
   , mMagneticFieldZ(const_cast<StRunInfo &>( rhs ).mMagneticFieldZ)
   , mSvtDriftVelocityScaler(const_cast<StRunInfo &>( rhs ).mSvtDriftVelocityScaler)
   , mZdcEastRate(const_cast<StRunInfo &>( rhs ).mZdcEastRate)
   , mZdcWestRate(const_cast<StRunInfo &>( rhs ).mZdcWestRate)
   , mZdcCoincidenceRate(const_cast<StRunInfo &>( rhs ).mZdcCoincidenceRate)
   , mBackgroundRate(const_cast<StRunInfo &>( rhs ).mBackgroundRate)
   , mL0RateToRich(const_cast<StRunInfo &>( rhs ).mL0RateToRich)
   , mBbcCoincidenceRate(const_cast<StRunInfo &>( rhs ).mBbcCoincidenceRate)
   , mBbcEastRate(const_cast<StRunInfo &>( rhs ).mBbcEastRate)
   , mBbcWestRate(const_cast<StRunInfo &>( rhs ).mBbcWestRate)
   , mBbcBlueBackgroundRate(const_cast<StRunInfo &>( rhs ).mBbcBlueBackgroundRate)
   , mBbcYellowBackgroundRate(const_cast<StRunInfo &>( rhs ).mBbcYellowBackgroundRate)
   , mSpaceChargeCorrectionMode(const_cast<StRunInfo &>( rhs ).mSpaceChargeCorrectionMode)
   , mSpaceCharge(const_cast<StRunInfo &>( rhs ).mSpaceCharge)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<2;i++) mBeamMassNumber[i] = rhs.mBeamMassNumber[i];
   for (Int_t i=0;i<2;i++) mTpcDriftVelocity[i] = rhs.mTpcDriftVelocity[i];
   for (Int_t i=0;i<2;i++) mBeamEnergy[i] = rhs.mBeamEnergy[i];
   for (Int_t i=0;i<2;i++) mInitialBeamIntensity[i] = rhs.mInitialBeamIntensity[i];
   for (Int_t i=0;i<2;i++) mBeamLifeTime[i] = rhs.mBeamLifeTime[i];
   for (Int_t i=0;i<2;i++) mBeamFillNumber[i] = rhs.mBeamFillNumber[i];
}
StRunInfo::~StRunInfo() {
}
#endif // StRunInfo_cxx

#ifndef StEventInfo_cxx
#define StEventInfo_cxx
StEventInfo::StEventInfo() {
}
StEventInfo::StEventInfo(const StEventInfo & rhs)
   : StObject(const_cast<StEventInfo &>( rhs ))
   , mType(const_cast<StEventInfo &>( rhs ).mType)
   , mRunId(const_cast<StEventInfo &>( rhs ).mRunId)
   , mId(const_cast<StEventInfo &>( rhs ).mId)
   , mTime(const_cast<StEventInfo &>( rhs ).mTime)
   , mTriggerMask(const_cast<StEventInfo &>( rhs ).mTriggerMask)
   , mEventSize(const_cast<StEventInfo &>( rhs ).mEventSize)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<2;i++) mBunchCrossingNumber[i] = rhs.mBunchCrossingNumber[i];
}
StEventInfo::~StEventInfo() {
}
#endif // StEventInfo_cxx

#ifndef StEventSummary_cxx
#define StEventSummary_cxx
StEventSummary::StEventSummary() {
}
StEventSummary::StEventSummary(const StEventSummary & rhs)
   : StObject(const_cast<StEventSummary &>( rhs ))
   , mNumberOfTracks(const_cast<StEventSummary &>( rhs ).mNumberOfTracks)
   , mNumberOfGoodTracks(const_cast<StEventSummary &>( rhs ).mNumberOfGoodTracks)
   , mNumberOfGoodPrimaryTracks(const_cast<StEventSummary &>( rhs ).mNumberOfGoodPrimaryTracks)
   , mNumberOfPositiveTracks(const_cast<StEventSummary &>( rhs ).mNumberOfPositiveTracks)
   , mNumberOfNegativeTracks(const_cast<StEventSummary &>( rhs ).mNumberOfNegativeTracks)
   , mNumberOfExoticTracks(const_cast<StEventSummary &>( rhs ).mNumberOfExoticTracks)
   , mNumberOfVertices(const_cast<StEventSummary &>( rhs ).mNumberOfVertices)
   , mNumberOfVertexTypes(const_cast<StEventSummary &>( rhs ).mNumberOfVertexTypes)
   , mNumberOfPileupVertices(const_cast<StEventSummary &>( rhs ).mNumberOfPileupVertices)
   , mMeanPt(const_cast<StEventSummary &>( rhs ).mMeanPt)
   , mMeanPt2(const_cast<StEventSummary &>( rhs ).mMeanPt2)
   , mMeanEta(const_cast<StEventSummary &>( rhs ).mMeanEta)
   , mRmsEta(const_cast<StEventSummary &>( rhs ).mRmsEta)
   , mPrimaryVertexPos(const_cast<StEventSummary &>( rhs ).mPrimaryVertexPos)
   , mVertexTypeArraySize(const_cast<StEventSummary &>( rhs ).mVertexTypeArraySize)
   , mPhiBinsSize(const_cast<StEventSummary &>( rhs ).mPhiBinsSize)
   , mPtAndEtaBinsSize(const_cast<StEventSummary &>( rhs ).mPtAndEtaBinsSize)
   , mHistogramSize(const_cast<StEventSummary &>( rhs ).mHistogramSize)
   , mEtaBins(const_cast<StEventSummary &>( rhs ).mEtaBins)
   , mPtBins(const_cast<StEventSummary &>( rhs ).mPtBins)
   , mPhiBins(const_cast<StEventSummary &>( rhs ).mPhiBins)
   , mEtaOfTracksHisto(const_cast<StEventSummary &>( rhs ).mEtaOfTracksHisto)
   , mPtOfTracksHisto(const_cast<StEventSummary &>( rhs ).mPtOfTracksHisto)
   , mPhiOfTracksHisto(const_cast<StEventSummary &>( rhs ).mPhiOfTracksHisto)
   , mEneryVsEtaHisto(const_cast<StEventSummary &>( rhs ).mEneryVsEtaHisto)
   , mEnergyVsPhiHisto(const_cast<StEventSummary &>( rhs ).mEnergyVsPhiHisto)
   , mMagneticFieldZ(const_cast<StEventSummary &>( rhs ).mMagneticFieldZ)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StEventSummary::~StEventSummary() {
}
#endif // StEventSummary_cxx

#ifndef StVpdTriggerDetector_cxx
#define StVpdTriggerDetector_cxx
StVpdTriggerDetector::StVpdTriggerDetector() {
}
StVpdTriggerDetector::StVpdTriggerDetector(const StVpdTriggerDetector & rhs)
   : StObject(const_cast<StVpdTriggerDetector &>( rhs ))
   , mTimeDifference(const_cast<StVpdTriggerDetector &>( rhs ).mTimeDifference)
   , mYear(const_cast<StVpdTriggerDetector &>( rhs ).mYear)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<32;i++) (&(mADC[0][0]))[i] = (&(rhs.mADC[0][0]))[i];
   for (Int_t i=0;i<32;i++) (&(mTDC[0][0]))[i] = (&(rhs.mTDC[0][0]))[i];
   for (Int_t i=0;i<32;i++) (&(mADCmxq[0][0]))[i] = (&(rhs.mADCmxq[0][0]))[i];
   for (Int_t i=0;i<32;i++) (&(mTDCmxq[0][0]))[i] = (&(rhs.mTDCmxq[0][0]))[i];
   for (Int_t i=0;i<2;i++) mEarliestTDC[i] = rhs.mEarliestTDC[i];
}
StVpdTriggerDetector::~StVpdTriggerDetector() {
}
#endif // StVpdTriggerDetector_cxx

#ifndef StMtdTriggerDetector_cxx
#define StMtdTriggerDetector_cxx
StMtdTriggerDetector::StMtdTriggerDetector() {
}
StMtdTriggerDetector::StMtdTriggerDetector(const StMtdTriggerDetector & rhs)
   : StObject(const_cast<StMtdTriggerDetector &>( rhs ))
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<16;i++) (&(mADC[0][0]))[i] = (&(rhs.mADC[0][0]))[i];
   for (Int_t i=0;i<16;i++) (&(mTDC[0][0]))[i] = (&(rhs.mTDC[0][0]))[i];
}
StMtdTriggerDetector::~StMtdTriggerDetector() {
}
#endif // StMtdTriggerDetector_cxx

#ifndef StCtbTriggerDetector_cxx
#define StCtbTriggerDetector_cxx
StCtbTriggerDetector::StCtbTriggerDetector() {
}
StCtbTriggerDetector::StCtbTriggerDetector(const StCtbTriggerDetector & rhs)
   : StObject(const_cast<StCtbTriggerDetector &>( rhs ))
   , mNumberOfPreSamples(const_cast<StCtbTriggerDetector &>( rhs ).mNumberOfPreSamples)
   , mNumberOfPostSamples(const_cast<StCtbTriggerDetector &>( rhs ).mNumberOfPostSamples)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<2640;i++) (&(mMips[0][0][0]))[i] = (&(rhs.mMips[0][0][0]))[i];
   for (Int_t i=0;i<2640;i++) (&(mTime[0][0][0]))[i] = (&(rhs.mTime[0][0][0]))[i];
   for (Int_t i=0;i<176;i++) (&(mAux[0][0]))[i] = (&(rhs.mAux[0][0]))[i];
}
StCtbTriggerDetector::~StCtbTriggerDetector() {
}
#endif // StCtbTriggerDetector_cxx

#ifndef StZdcTriggerDetector_cxx
#define StZdcTriggerDetector_cxx
StZdcTriggerDetector::StZdcTriggerDetector() {
}
StZdcTriggerDetector::StZdcTriggerDetector(const StZdcTriggerDetector & rhs)
   : StObject(const_cast<StZdcTriggerDetector &>( rhs ))
   , mSum(const_cast<StZdcTriggerDetector &>( rhs ).mSum)
   , mVertexZ(const_cast<StZdcTriggerDetector &>( rhs ).mVertexZ)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<16;i++) mAdc[i] = rhs.mAdc[i];
   for (Int_t i=0;i<16;i++) mTdc[i] = rhs.mTdc[i];
   for (Int_t i=0;i<2;i++) mSumAdc[i] = rhs.mSumAdc[i];
   for (Int_t i=0;i<16;i++) mZdcSmdEast[i] = rhs.mZdcSmdEast[i];
   for (Int_t i=0;i<16;i++) mZdcSmdWest[i] = rhs.mZdcSmdWest[i];
}
StZdcTriggerDetector::~StZdcTriggerDetector() {
}
#endif // StZdcTriggerDetector_cxx

#ifndef StBbcTriggerDetector_cxx
#define StBbcTriggerDetector_cxx
StBbcTriggerDetector::StBbcTriggerDetector() {
}
StBbcTriggerDetector::StBbcTriggerDetector(const StBbcTriggerDetector & rhs)
   : StObject(const_cast<StBbcTriggerDetector &>( rhs ))
   , mYear(const_cast<StBbcTriggerDetector &>( rhs ).mYear)
   , mDSMVTX(const_cast<StBbcTriggerDetector &>( rhs ).mDSMVTX)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<48;i++) mAdc[i] = rhs.mAdc[i];
   for (Int_t i=0;i<48;i++) mTdc[i] = rhs.mTdc[i];
   for (Int_t i=0;i<2;i++) mReg[i] = rhs.mReg[i];
   for (Int_t i=0;i<128;i++) mPed[i] = rhs.mPed[i];
   for (Int_t i=0;i<32;i++) mScl[i] = rhs.mScl[i];
}
StBbcTriggerDetector::~StBbcTriggerDetector() {
}
#endif // StBbcTriggerDetector_cxx

#ifndef StEmcTriggerDetector_cxx
#define StEmcTriggerDetector_cxx
StEmcTriggerDetector::StEmcTriggerDetector() {
}
StEmcTriggerDetector::StEmcTriggerDetector(const StEmcTriggerDetector & rhs)
   : StObject(const_cast<StEmcTriggerDetector &>( rhs ))
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<300;i++) mHighTower[i] = rhs.mHighTower[i];
   for (Int_t i=0;i<300;i++) mPatch[i] = rhs.mPatch[i];
   for (Int_t i=0;i<90;i++) mEHighTower[i] = rhs.mEHighTower[i];
   for (Int_t i=0;i<90;i++) mEPatch[i] = rhs.mEPatch[i];
   for (Int_t i=0;i<48;i++) mBemcLayer1[i] = rhs.mBemcLayer1[i];
   for (Int_t i=0;i<16;i++) mEemcLayer1[i] = rhs.mEemcLayer1[i];
   for (Int_t i=0;i<8;i++) mEmcLayer2[i] = rhs.mEmcLayer2[i];
}
StEmcTriggerDetector::~StEmcTriggerDetector() {
}
#endif // StEmcTriggerDetector_cxx

#ifndef StFpdTriggerDetector_cxx
#define StFpdTriggerDetector_cxx
StFpdTriggerDetector::StFpdTriggerDetector() {
}
StFpdTriggerDetector::StFpdTriggerDetector(const StFpdTriggerDetector & rhs)
   : StObject(const_cast<StFpdTriggerDetector &>( rhs ))
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<49;i++) mEN[i] = rhs.mEN[i];
   for (Int_t i=0;i<49;i++) mES[i] = rhs.mES[i];
   for (Int_t i=0;i<25;i++) mET[i] = rhs.mET[i];
   for (Int_t i=0;i<25;i++) mEB[i] = rhs.mEB[i];
   for (Int_t i=0;i<7;i++) mEPN[i] = rhs.mEPN[i];
   for (Int_t i=0;i<7;i++) mEPS[i] = rhs.mEPS[i];
   for (Int_t i=0;i<49;i++) mWN[i] = rhs.mWN[i];
   for (Int_t i=0;i<49;i++) mWS[i] = rhs.mWS[i];
   for (Int_t i=0;i<25;i++) mWT[i] = rhs.mWT[i];
   for (Int_t i=0;i<25;i++) mWB[i] = rhs.mWB[i];
   for (Int_t i=0;i<7;i++) mWPN[i] = rhs.mWPN[i];
   for (Int_t i=0;i<7;i++) mWPS[i] = rhs.mWPS[i];
   for (Int_t i=0;i<48;i++) (&(mLayer1[0][0][0]))[i] = (&(rhs.mLayer1[0][0][0]))[i];
   for (Int_t i=0;i<12;i++) (&(mLayer2[0][0]))[i] = (&(rhs.mLayer2[0][0]))[i];
}
StFpdTriggerDetector::~StFpdTriggerDetector() {
}
#endif // StFpdTriggerDetector_cxx

#ifndef StFmsTriggerDetector_cxx
#define StFmsTriggerDetector_cxx
StFmsTriggerDetector::StFmsTriggerDetector() {
}
StFmsTriggerDetector::StFmsTriggerDetector(const StFmsTriggerDetector & rhs)
   : StObject(const_cast<StFmsTriggerDetector &>( rhs ))
   , mNumQTdata(const_cast<StFmsTriggerDetector &>( rhs ).mNumQTdata)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<1600;i++) mQTdata[i] = rhs.mQTdata[i];
   for (Int_t i=0;i<256;i++) mDSM[i] = rhs.mDSM[i];
   for (Int_t i=0;i<112;i++) mDSM01[i] = rhs.mDSM01[i];
   for (Int_t i=0;i<16;i++) mDSM02[i] = rhs.mDSM02[i];
   for (Int_t i=0;i<16;i++) mDSM1[i] = rhs.mDSM1[i];
   for (Int_t i=0;i<8;i++) mDSM2[i] = rhs.mDSM2[i];
}
StFmsTriggerDetector::~StFmsTriggerDetector() {
}
#endif // StFmsTriggerDetector_cxx

#ifndef StFpdCollection_cxx
#define StFpdCollection_cxx
StFpdCollection::StFpdCollection() {
}
StFpdCollection::StFpdCollection(const StFpdCollection & rhs)
   : StObject(const_cast<StFpdCollection &>( rhs ))
   , mToken(const_cast<StFpdCollection &>( rhs ).mToken)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<256;i++) mAdc[i] = rhs.mAdc[i];
   for (Int_t i=0;i<8;i++) mTdc[i] = rhs.mTdc[i];
   for (Int_t i=0;i<3;i++) mReg[i] = rhs.mReg[i];
   for (Int_t i=0;i<256;i++) mPed[i] = rhs.mPed[i];
   for (Int_t i=0;i<128;i++) mScl[i] = rhs.mScl[i];
}
StFpdCollection::~StFpdCollection() {
}
#endif // StFpdCollection_cxx

#ifndef StL0Trigger_cxx
#define StL0Trigger_cxx
StL0Trigger::StL0Trigger() {
}
StL0Trigger::StL0Trigger(const StL0Trigger & rhs)
   : StTrigger(const_cast<StL0Trigger &>( rhs ))
   , mMwcCtbMultiplicity(const_cast<StL0Trigger &>( rhs ).mMwcCtbMultiplicity)
   , mMwcCtbDipole(const_cast<StL0Trigger &>( rhs ).mMwcCtbDipole)
   , mMwcCtbTopology(const_cast<StL0Trigger &>( rhs ).mMwcCtbTopology)
   , mMwcCtbMoment(const_cast<StL0Trigger &>( rhs ).mMwcCtbMoment)
   , mDsmInput(const_cast<StL0Trigger &>( rhs ).mDsmInput)
   , mDetectorBusy(const_cast<StL0Trigger &>( rhs ).mDetectorBusy)
   , mTriggerToken(const_cast<StL0Trigger &>( rhs ).mTriggerToken)
   , mDsmAddress(const_cast<StL0Trigger &>( rhs ).mDsmAddress)
   , mAddBits(const_cast<StL0Trigger &>( rhs ).mAddBits)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<32;i++) mCoarsePixelArray[i] = rhs.mCoarsePixelArray[i];
   for (Int_t i=0;i<8;i++) mLastDsmArray[i] = rhs.mLastDsmArray[i];
   for (Int_t i=0;i<16;i++) mBcDataArray[i] = rhs.mBcDataArray[i];
}
StL0Trigger::~StL0Trigger() {
}
#endif // StL0Trigger_cxx

#ifndef StTrigger_cxx
#define StTrigger_cxx
StTrigger::StTrigger() {
}
StTrigger::StTrigger(const StTrigger & rhs)
   : StObject(const_cast<StTrigger &>( rhs ))
   , mTriggerActionWord(const_cast<StTrigger &>( rhs ).mTriggerActionWord)
   , mTriggerWord(const_cast<StTrigger &>( rhs ).mTriggerWord)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StTrigger::~StTrigger() {
}
#endif // StTrigger_cxx

#ifndef StMuL3EventSummary_cxx
#define StMuL3EventSummary_cxx
StMuL3EventSummary::StMuL3EventSummary() {
}
StMuL3EventSummary::StMuL3EventSummary(const StMuL3EventSummary & rhs)
   : TObject(const_cast<StMuL3EventSummary &>( rhs ))
   , mNumberOfProcessedEvents(const_cast<StMuL3EventSummary &>( rhs ).mNumberOfProcessedEvents)
   , mNumberReconstructedEvents(const_cast<StMuL3EventSummary &>( rhs ).mNumberReconstructedEvents)
   , mNumberOfTracks(const_cast<StMuL3EventSummary &>( rhs ).mNumberOfTracks)
   , mNumberOfAlgorithms(const_cast<StMuL3EventSummary &>( rhs ).mNumberOfAlgorithms)
   , mFlags(const_cast<StMuL3EventSummary &>( rhs ).mFlags)
   , mL0TriggerWord(const_cast<StMuL3EventSummary &>( rhs ).mL0TriggerWord)
   , mUnbiasedPreScale(const_cast<StMuL3EventSummary &>( rhs ).mUnbiasedPreScale)
   , mPrimaryVertex(const_cast<StMuL3EventSummary &>( rhs ).mPrimaryVertex)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuL3EventSummary::~StMuL3EventSummary() {
}
#endif // StMuL3EventSummary_cxx

#ifndef StMuTriggerIdCollection_cxx
#define StMuTriggerIdCollection_cxx
StMuTriggerIdCollection::StMuTriggerIdCollection() {
}
StMuTriggerIdCollection::StMuTriggerIdCollection(const StMuTriggerIdCollection & rhs)
   : StObject(const_cast<StMuTriggerIdCollection &>( rhs ))
   , mL1TriggerId(const_cast<StMuTriggerIdCollection &>( rhs ).mL1TriggerId)
   , mL2TriggerId(const_cast<StMuTriggerIdCollection &>( rhs ).mL2TriggerId)
   , mL3TriggerId(const_cast<StMuTriggerIdCollection &>( rhs ).mL3TriggerId)
   , mNTriggerId(const_cast<StMuTriggerIdCollection &>( rhs ).mNTriggerId)
   , mLETriggerId(const_cast<StMuTriggerIdCollection &>( rhs ).mLETriggerId)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuTriggerIdCollection::~StMuTriggerIdCollection() {
}
#endif // StMuTriggerIdCollection_cxx

#ifndef StTriggerId_cxx
#define StTriggerId_cxx
StTriggerId::StTriggerId() {
}
StTriggerId::StTriggerId(const StTriggerId & rhs)
   : StObject(const_cast<StTriggerId &>( rhs ))
   , mMask(const_cast<StTriggerId &>( rhs ).mMask)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<64;i++) mId[i] = rhs.mId[i];
   for (Int_t i=0;i<64;i++) mVersion[i] = rhs.mVersion[i];
   for (Int_t i=0;i<64;i++) mNameVersion[i] = rhs.mNameVersion[i];
   for (Int_t i=0;i<64;i++) mThresholdVersion[i] = rhs.mThresholdVersion[i];
   for (Int_t i=0;i<64;i++) mPrescaleVersion[i] = rhs.mPrescaleVersion[i];
}
StTriggerId::~StTriggerId() {
}
#endif // StTriggerId_cxx

#ifndef StMuPrimaryVertex_cxx
#define StMuPrimaryVertex_cxx
StMuPrimaryVertex::StMuPrimaryVertex() {
}
StMuPrimaryVertex::StMuPrimaryVertex(const StMuPrimaryVertex & rhs)
   : TObject(const_cast<StMuPrimaryVertex &>( rhs ))
   , mFlag(const_cast<StMuPrimaryVertex &>( rhs ).mFlag)
   , mPosition(const_cast<StMuPrimaryVertex &>( rhs ).mPosition)
   , mPosError(const_cast<StMuPrimaryVertex &>( rhs ).mPosError)
   , mVertexFinderId(const_cast<StMuPrimaryVertex &>( rhs ).mVertexFinderId)
   , mRanking(const_cast<StMuPrimaryVertex &>( rhs ).mRanking)
   , mNTracksUsed(const_cast<StMuPrimaryVertex &>( rhs ).mNTracksUsed)
   , mNBTOFMatch(const_cast<StMuPrimaryVertex &>( rhs ).mNBTOFMatch)
   , mNCTBMatch(const_cast<StMuPrimaryVertex &>( rhs ).mNCTBMatch)
   , mNBEMCMatch(const_cast<StMuPrimaryVertex &>( rhs ).mNBEMCMatch)
   , mNEEMCMatch(const_cast<StMuPrimaryVertex &>( rhs ).mNEEMCMatch)
   , mNBTOFNotMatch(const_cast<StMuPrimaryVertex &>( rhs ).mNBTOFNotMatch)
   , mNCTBNotMatch(const_cast<StMuPrimaryVertex &>( rhs ).mNCTBNotMatch)
   , mNBEMCNotMatch(const_cast<StMuPrimaryVertex &>( rhs ).mNBEMCNotMatch)
   , mNEEMCNotMatch(const_cast<StMuPrimaryVertex &>( rhs ).mNEEMCNotMatch)
   , mNCrossCentralMembrane(const_cast<StMuPrimaryVertex &>( rhs ).mNCrossCentralMembrane)
   , mNTracksWithPromptHit(const_cast<StMuPrimaryVertex &>( rhs ).mNTracksWithPromptHit)
   , mNPostXTracks(const_cast<StMuPrimaryVertex &>( rhs ).mNPostXTracks)
   , mSumTrackPt(const_cast<StMuPrimaryVertex &>( rhs ).mSumTrackPt)
   , mMeanDip(const_cast<StMuPrimaryVertex &>( rhs ).mMeanDip)
   , mChiSquared(const_cast<StMuPrimaryVertex &>( rhs ).mChiSquared)
   , mNTracks(const_cast<StMuPrimaryVertex &>( rhs ).mNTracks)
   , mNTpcWestOnly(const_cast<StMuPrimaryVertex &>( rhs ).mNTpcWestOnly)
   , mNTpcEastOnly(const_cast<StMuPrimaryVertex &>( rhs ).mNTpcEastOnly)
   , mRefMultNeg(const_cast<StMuPrimaryVertex &>( rhs ).mRefMultNeg)
   , mRefMultPos(const_cast<StMuPrimaryVertex &>( rhs ).mRefMultPos)
   , mRefMultFtpcWest(const_cast<StMuPrimaryVertex &>( rhs ).mRefMultFtpcWest)
   , mRefMultFtpcEast(const_cast<StMuPrimaryVertex &>( rhs ).mRefMultFtpcEast)
   , mIdTruth(const_cast<StMuPrimaryVertex &>( rhs ).mIdTruth)
   , mQuality(const_cast<StMuPrimaryVertex &>( rhs ).mQuality)
   , mIdParent(const_cast<StMuPrimaryVertex &>( rhs ).mIdParent)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuPrimaryVertex::~StMuPrimaryVertex() {
}
#endif // StMuPrimaryVertex_cxx

#ifndef StMuTrack_cxx
#define StMuTrack_cxx
StMuTrack::StMuTrack() {
}
StMuTrack::StMuTrack(const StMuTrack & rhs)
   : TObject(const_cast<StMuTrack &>( rhs ))
   , mId(const_cast<StMuTrack &>( rhs ).mId)
   , mType(const_cast<StMuTrack &>( rhs ).mType)
   , mFlag(const_cast<StMuTrack &>( rhs ).mFlag)
   , mFlagExtension(const_cast<StMuTrack &>( rhs ).mFlagExtension)
   , mIndex2Global(const_cast<StMuTrack &>( rhs ).mIndex2Global)
   , mIndex2RichSpectra(const_cast<StMuTrack &>( rhs ).mIndex2RichSpectra)
   , mIndex2BTofHit(const_cast<StMuTrack &>( rhs ).mIndex2BTofHit)
   , mIndex2MtdHit(const_cast<StMuTrack &>( rhs ).mIndex2MtdHit)
   , mVertexIndex(const_cast<StMuTrack &>( rhs ).mVertexIndex)
   , mNHits(const_cast<StMuTrack &>( rhs ).mNHits)
   , mNHitsPoss(const_cast<StMuTrack &>( rhs ).mNHitsPoss)
   , mNHitsDedx(const_cast<StMuTrack &>( rhs ).mNHitsDedx)
   , mNHitsFit(const_cast<StMuTrack &>( rhs ).mNHitsFit)
   , mNHitsPossInner(const_cast<StMuTrack &>( rhs ).mNHitsPossInner)
   , mNHitsFitInner(const_cast<StMuTrack &>( rhs ).mNHitsFitInner)
   , mNHitsPossTpc(const_cast<StMuTrack &>( rhs ).mNHitsPossTpc)
   , mNHitsFitTpc(const_cast<StMuTrack &>( rhs ).mNHitsFitTpc)
   , mPidProbElectron(const_cast<StMuTrack &>( rhs ).mPidProbElectron)
   , mPidProbPion(const_cast<StMuTrack &>( rhs ).mPidProbPion)
   , mPidProbKaon(const_cast<StMuTrack &>( rhs ).mPidProbKaon)
   , mPidProbProton(const_cast<StMuTrack &>( rhs ).mPidProbProton)
   , mNSigmaElectron(const_cast<StMuTrack &>( rhs ).mNSigmaElectron)
   , mNSigmaPion(const_cast<StMuTrack &>( rhs ).mNSigmaPion)
   , mNSigmaKaon(const_cast<StMuTrack &>( rhs ).mNSigmaKaon)
   , mNSigmaProton(const_cast<StMuTrack &>( rhs ).mNSigmaProton)
   , mdEdx(const_cast<StMuTrack &>( rhs ).mdEdx)
   , mChiSqXY(const_cast<StMuTrack &>( rhs ).mChiSqXY)
   , mChiSqZ(const_cast<StMuTrack &>( rhs ).mChiSqZ)
   , mPt(const_cast<StMuTrack &>( rhs ).mPt)
   , mEta(const_cast<StMuTrack &>( rhs ).mEta)
   , mPhi(const_cast<StMuTrack &>( rhs ).mPhi)
   , mTopologyMap(const_cast<StMuTrack &>( rhs ).mTopologyMap)
   , mP(const_cast<StMuTrack &>( rhs ).mP)
   , mDCA(const_cast<StMuTrack &>( rhs ).mDCA)
   , mDCAGlobal(const_cast<StMuTrack &>( rhs ).mDCAGlobal)
   , mFirstPoint(const_cast<StMuTrack &>( rhs ).mFirstPoint)
   , mLastPoint(const_cast<StMuTrack &>( rhs ).mLastPoint)
   , mHelix(const_cast<StMuTrack &>( rhs ).mHelix)
   , mOuterHelix(const_cast<StMuTrack &>( rhs ).mOuterHelix)
   , mProbPidTraits(const_cast<StMuTrack &>( rhs ).mProbPidTraits)
   , mBTofPidTraits(const_cast<StMuTrack &>( rhs ).mBTofPidTraits)
   , mMtdPidTraits(const_cast<StMuTrack &>( rhs ).mMtdPidTraits)
   , mIndex2Cov(const_cast<StMuTrack &>( rhs ).mIndex2Cov)
   , mIdTruth(const_cast<StMuTrack &>( rhs ).mIdTruth)
   , mQuality(const_cast<StMuTrack &>( rhs ).mQuality)
   , mIdParentVx(const_cast<StMuTrack &>( rhs ).mIdParentVx)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuTrack::~StMuTrack() {
}
#endif // StMuTrack_cxx

#ifndef StMuHelix_cxx
#define StMuHelix_cxx
StMuHelix::StMuHelix() {
}
StMuHelix::StMuHelix(const StMuHelix & rhs)
   : TObject(const_cast<StMuHelix &>( rhs ))
   , mP(const_cast<StMuHelix &>( rhs ).mP)
   , mOrigin(const_cast<StMuHelix &>( rhs ).mOrigin)
   , mQ(const_cast<StMuHelix &>( rhs ).mQ)
   , mB(const_cast<StMuHelix &>( rhs ).mB)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuHelix::~StMuHelix() {
}
#endif // StMuHelix_cxx

#ifndef StMuProbPidTraits_cxx
#define StMuProbPidTraits_cxx
StMuProbPidTraits::StMuProbPidTraits() {
}
StMuProbPidTraits::StMuProbPidTraits(const StMuProbPidTraits & rhs)
   : TObject(const_cast<StMuProbPidTraits &>( rhs ))
   , mNDF(const_cast<StMuProbPidTraits &>( rhs ).mNDF)
   , mdEdxFit(const_cast<StMuProbPidTraits &>( rhs ).mdEdxFit)
   , mdEdxErrorFit(const_cast<StMuProbPidTraits &>( rhs ).mdEdxErrorFit)
   , mdEdxTruncated(const_cast<StMuProbPidTraits &>( rhs ).mdEdxTruncated)
   , mdEdxErrorTruncated(const_cast<StMuProbPidTraits &>( rhs ).mdEdxErrorTruncated)
   , mdNdxFit(const_cast<StMuProbPidTraits &>( rhs ).mdNdxFit)
   , mdNdxErrorFit(const_cast<StMuProbPidTraits &>( rhs ).mdNdxErrorFit)
   , mdEdxTrackLength(const_cast<StMuProbPidTraits &>( rhs ).mdEdxTrackLength)
   , mLog2dX(const_cast<StMuProbPidTraits &>( rhs ).mLog2dX)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<9;i++) mProbabilities[i] = rhs.mProbabilities[i];
}
StMuProbPidTraits::~StMuProbPidTraits() {
}
#endif // StMuProbPidTraits_cxx

#ifndef StMuBTofPidTraits_cxx
#define StMuBTofPidTraits_cxx
StMuBTofPidTraits::StMuBTofPidTraits() {
}
StMuBTofPidTraits::StMuBTofPidTraits(const StMuBTofPidTraits & rhs)
   : TObject(const_cast<StMuBTofPidTraits &>( rhs ))
   , mMatchFlag(const_cast<StMuBTofPidTraits &>( rhs ).mMatchFlag)
   , mYLocal(const_cast<StMuBTofPidTraits &>( rhs ).mYLocal)
   , mZLocal(const_cast<StMuBTofPidTraits &>( rhs ).mZLocal)
   , mThetaLocal(const_cast<StMuBTofPidTraits &>( rhs ).mThetaLocal)
   , mPosition(const_cast<StMuBTofPidTraits &>( rhs ).mPosition)
   , mTimeOfFlight(const_cast<StMuBTofPidTraits &>( rhs ).mTimeOfFlight)
   , mPathLength(const_cast<StMuBTofPidTraits &>( rhs ).mPathLength)
   , mBeta(const_cast<StMuBTofPidTraits &>( rhs ).mBeta)
   , mSigmaElectron(const_cast<StMuBTofPidTraits &>( rhs ).mSigmaElectron)
   , mSigmaPion(const_cast<StMuBTofPidTraits &>( rhs ).mSigmaPion)
   , mSigmaKaon(const_cast<StMuBTofPidTraits &>( rhs ).mSigmaKaon)
   , mSigmaProton(const_cast<StMuBTofPidTraits &>( rhs ).mSigmaProton)
   , mProbElectron(const_cast<StMuBTofPidTraits &>( rhs ).mProbElectron)
   , mProbPion(const_cast<StMuBTofPidTraits &>( rhs ).mProbPion)
   , mProbKaon(const_cast<StMuBTofPidTraits &>( rhs ).mProbKaon)
   , mProbProton(const_cast<StMuBTofPidTraits &>( rhs ).mProbProton)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuBTofPidTraits::~StMuBTofPidTraits() {
}
#endif // StMuBTofPidTraits_cxx

#ifndef StMuMtdPidTraits_cxx
#define StMuMtdPidTraits_cxx
StMuMtdPidTraits::StMuMtdPidTraits() {
}
StMuMtdPidTraits::StMuMtdPidTraits(const StMuMtdPidTraits & rhs)
   : TObject(const_cast<StMuMtdPidTraits &>( rhs ))
   , mMatchFlag(const_cast<StMuMtdPidTraits &>( rhs ).mMatchFlag)
   , mYLocal(const_cast<StMuMtdPidTraits &>( rhs ).mYLocal)
   , mZLocal(const_cast<StMuMtdPidTraits &>( rhs ).mZLocal)
   , mThetaLocal(const_cast<StMuMtdPidTraits &>( rhs ).mThetaLocal)
   , mPosition(const_cast<StMuMtdPidTraits &>( rhs ).mPosition)
   , mTimeOfFlight(const_cast<StMuMtdPidTraits &>( rhs ).mTimeOfFlight)
   , mPathLength(const_cast<StMuMtdPidTraits &>( rhs ).mPathLength)
   , mBeta(const_cast<StMuMtdPidTraits &>( rhs ).mBeta)
   , mSigmaMuon(const_cast<StMuMtdPidTraits &>( rhs ).mSigmaMuon)
   , mProbMuon(const_cast<StMuMtdPidTraits &>( rhs ).mProbMuon)
   , mExpTimeOfFlight(const_cast<StMuMtdPidTraits &>( rhs ).mExpTimeOfFlight)
   , mDeltaY(const_cast<StMuMtdPidTraits &>( rhs ).mDeltaY)
   , mDeltaZ(const_cast<StMuMtdPidTraits &>( rhs ).mDeltaZ)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuMtdPidTraits::~StMuMtdPidTraits() {
}
#endif // StMuMtdPidTraits_cxx

#ifndef StRichSpectra_cxx
#define StRichSpectra_cxx
StRichSpectra::StRichSpectra() {
}
StRichSpectra::StRichSpectra(const StRichSpectra & rhs)
   : StObject(const_cast<StRichSpectra &>( rhs ))
   , mExtrapolatedX(const_cast<StRichSpectra &>( rhs ).mExtrapolatedX)
   , mExtrapolatedY(const_cast<StRichSpectra &>( rhs ).mExtrapolatedY)
   , mDx(const_cast<StRichSpectra &>( rhs ).mDx)
   , mDy(const_cast<StRichSpectra &>( rhs ).mDy)
   , mCdx(const_cast<StRichSpectra &>( rhs ).mCdx)
   , mCdy(const_cast<StRichSpectra &>( rhs ).mCdy)
   , mCherenkovAngle(const_cast<StRichSpectra &>( rhs ).mCherenkovAngle)
   , mCherenkovAngleSigma(const_cast<StRichSpectra &>( rhs ).mCherenkovAngleSigma)
   , mNumberOfPhotons(const_cast<StRichSpectra &>( rhs ).mNumberOfPhotons)
   , mPeakAngle(const_cast<StRichSpectra &>( rhs ).mPeakAngle)
   , mPeakPhotons(const_cast<StRichSpectra &>( rhs ).mPeakPhotons)
   , mTotalPhotons(const_cast<StRichSpectra &>( rhs ).mTotalPhotons)
   , mMassSquared(const_cast<StRichSpectra &>( rhs ).mMassSquared)
   , mLineIntegralRatio(const_cast<StRichSpectra &>( rhs ).mLineIntegralRatio)
   , mLineIntegral(const_cast<StRichSpectra &>( rhs ).mLineIntegral)
   , mAlpha(const_cast<StRichSpectra &>( rhs ).mAlpha)
   , mFlag(const_cast<StRichSpectra &>( rhs ).mFlag)
   , mReserved(const_cast<StRichSpectra &>( rhs ).mReserved)
   , mDpi(const_cast<StRichSpectra &>( rhs ).mDpi)
   , mDk(const_cast<StRichSpectra &>( rhs ).mDk)
   , mDp(const_cast<StRichSpectra &>( rhs ).mDp)
   , mNDpi(const_cast<StRichSpectra &>( rhs ).mNDpi)
   , mNDk(const_cast<StRichSpectra &>( rhs ).mNDk)
   , mNDp(const_cast<StRichSpectra &>( rhs ).mNDp)
   , mVersion(const_cast<StRichSpectra &>( rhs ).mVersion)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StRichSpectra::~StRichSpectra() {
}
#endif // StRichSpectra_cxx

#ifndef StDetectorState_cxx
#define StDetectorState_cxx
StDetectorState::StDetectorState() {
}
StDetectorState::StDetectorState(const StDetectorState & rhs)
   : StObject(const_cast<StDetectorState &>( rhs ))
   , mDetectorId(const_cast<StDetectorState &>( rhs ).mDetectorId)
   , mIsGood(const_cast<StDetectorState &>( rhs ).mIsGood)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StDetectorState::~StDetectorState() {
}
#endif // StDetectorState_cxx

#ifndef StL3AlgorithmInfo_cxx
#define StL3AlgorithmInfo_cxx
StL3AlgorithmInfo::StL3AlgorithmInfo() {
}
StL3AlgorithmInfo::StL3AlgorithmInfo(const StL3AlgorithmInfo & rhs)
   : StObject(const_cast<StL3AlgorithmInfo &>( rhs ))
   , mId(const_cast<StL3AlgorithmInfo &>( rhs ).mId)
   , mOn(const_cast<StL3AlgorithmInfo &>( rhs ).mOn)
   , mAccept(const_cast<StL3AlgorithmInfo &>( rhs ).mAccept)
   , mBuild(const_cast<StL3AlgorithmInfo &>( rhs ).mBuild)
   , mNumberOfProcessedEvents(const_cast<StL3AlgorithmInfo &>( rhs ).mNumberOfProcessedEvents)
   , mNumberOfAcceptedEvents(const_cast<StL3AlgorithmInfo &>( rhs ).mNumberOfAcceptedEvents)
   , mNumberOfBuildEvents(const_cast<StL3AlgorithmInfo &>( rhs ).mNumberOfBuildEvents)
   , mDataSize(const_cast<StL3AlgorithmInfo &>( rhs ).mDataSize)
   , mDataArray(const_cast<StL3AlgorithmInfo &>( rhs ).mDataArray)
   , mPreScale(const_cast<StL3AlgorithmInfo &>( rhs ).mPreScale)
   , mPostScale(const_cast<StL3AlgorithmInfo &>( rhs ).mPostScale)
   , mIntParameterSize(const_cast<StL3AlgorithmInfo &>( rhs ).mIntParameterSize)
   , mIntParameterArray(const_cast<StL3AlgorithmInfo &>( rhs ).mIntParameterArray)
   , mFloatParameterSize(const_cast<StL3AlgorithmInfo &>( rhs ).mFloatParameterSize)
   , mFloatParameterArray(const_cast<StL3AlgorithmInfo &>( rhs ).mFloatParameterArray)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StL3AlgorithmInfo::~StL3AlgorithmInfo() {
}
#endif // StL3AlgorithmInfo_cxx

#ifndef StDcaGeometry_cxx
#define StDcaGeometry_cxx
StDcaGeometry::StDcaGeometry() {
}
StDcaGeometry::StDcaGeometry(const StDcaGeometry & rhs)
   : StObject(const_cast<StDcaGeometry &>( rhs ))
   , mImp(const_cast<StDcaGeometry &>( rhs ).mImp)
   , mZ(const_cast<StDcaGeometry &>( rhs ).mZ)
   , mPsi(const_cast<StDcaGeometry &>( rhs ).mPsi)
   , mPti(const_cast<StDcaGeometry &>( rhs ).mPti)
   , mTan(const_cast<StDcaGeometry &>( rhs ).mTan)
   , mCurv(const_cast<StDcaGeometry &>( rhs ).mCurv)
   , mImpImp(const_cast<StDcaGeometry &>( rhs ).mImpImp)
   , mZImp(const_cast<StDcaGeometry &>( rhs ).mZImp)
   , mZZ(const_cast<StDcaGeometry &>( rhs ).mZZ)
   , mPsiImp(const_cast<StDcaGeometry &>( rhs ).mPsiImp)
   , mPsiZ(const_cast<StDcaGeometry &>( rhs ).mPsiZ)
   , mPsiPsi(const_cast<StDcaGeometry &>( rhs ).mPsiPsi)
   , mPtiImp(const_cast<StDcaGeometry &>( rhs ).mPtiImp)
   , mPtiZ(const_cast<StDcaGeometry &>( rhs ).mPtiZ)
   , mPtiPsi(const_cast<StDcaGeometry &>( rhs ).mPtiPsi)
   , mPtiPti(const_cast<StDcaGeometry &>( rhs ).mPtiPti)
   , mTanImp(const_cast<StDcaGeometry &>( rhs ).mTanImp)
   , mTanZ(const_cast<StDcaGeometry &>( rhs ).mTanZ)
   , mTanPsi(const_cast<StDcaGeometry &>( rhs ).mTanPsi)
   , mTanPti(const_cast<StDcaGeometry &>( rhs ).mTanPti)
   , mTanTan(const_cast<StDcaGeometry &>( rhs ).mTanTan)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StDcaGeometry::~StDcaGeometry() {
}
#endif // StDcaGeometry_cxx

#ifndef StMuPrimaryTrackCovariance_cxx
#define StMuPrimaryTrackCovariance_cxx
StMuPrimaryTrackCovariance::StMuPrimaryTrackCovariance() {
}
StMuPrimaryTrackCovariance::StMuPrimaryTrackCovariance(const StMuPrimaryTrackCovariance & rhs)
   : TObject(const_cast<StMuPrimaryTrackCovariance &>( rhs ))
   , mTanTan(const_cast<StMuPrimaryTrackCovariance &>( rhs ).mTanTan)
   , mPsiTan(const_cast<StMuPrimaryTrackCovariance &>( rhs ).mPsiTan)
   , mPsiPsi(const_cast<StMuPrimaryTrackCovariance &>( rhs ).mPsiPsi)
   , mPtiTan(const_cast<StMuPrimaryTrackCovariance &>( rhs ).mPtiTan)
   , mPtiPsi(const_cast<StMuPrimaryTrackCovariance &>( rhs ).mPtiPsi)
   , mPtiPti(const_cast<StMuPrimaryTrackCovariance &>( rhs ).mPtiPti)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuPrimaryTrackCovariance::~StMuPrimaryTrackCovariance() {
}
#endif // StMuPrimaryTrackCovariance_cxx

#ifndef StMuRpsCollection_cxx
#define StMuRpsCollection_cxx
StMuRpsCollection::StMuRpsCollection() {
}
StMuRpsCollection::StMuRpsCollection(const StMuRpsCollection & rhs)
   : TObject(const_cast<StMuRpsCollection &>( rhs ))
   , mSiliconBunch(const_cast<StMuRpsCollection &>( rhs ).mSiliconBunch)
   , mTrackPoints(const_cast<StMuRpsCollection &>( rhs ).mTrackPoints)
   , mTracks(const_cast<StMuRpsCollection &>( rhs ).mTracks)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<8;i++) mNumberPlanes[i] = rhs.mNumberPlanes[i];
   for (Int_t i=0;i<8;i++) mNumberPlanesWithClusters[i] = rhs.mNumberPlanesWithClusters[i];
   for (Int_t i=0;i<8;i++) mStatusRomanPot[i] = rhs.mStatusRomanPot[i];
   for (Int_t i=0;i<16;i++) (&(mADC[0][0]))[i] = (&(rhs.mADC[0][0]))[i];
   for (Int_t i=0;i<16;i++) (&(mTAC[0][0]))[i] = (&(rhs.mTAC[0][0]))[i];
   for (Int_t i=0;i<32;i++) (&(mOffsetPlane[0][0]))[i] = (&(rhs.mOffsetPlane[0][0]))[i];
   for (Int_t i=0;i<32;i++) (&(mzPlane[0][0]))[i] = (&(rhs.mzPlane[0][0]))[i];
   for (Int_t i=0;i<32;i++) (&(mAnglePlane[0][0]))[i] = (&(rhs.mAnglePlane[0][0]))[i];
   for (Int_t i=0;i<32;i++) (&(mOrientationPlane[0][0]))[i] = (&(rhs.mOrientationPlane[0][0]))[i];
   for (Int_t i=0;i<32;i++) (&(mStatusPlane[0][0]))[i] = (&(rhs.mStatusPlane[0][0]))[i];
   for (Int_t i=0;i<32;i++) (&(mNumberOfClusters[0][0]))[i] = (&(rhs.mNumberOfClusters[0][0]))[i];
   for (Int_t i=0;i<32;i++) (&(mPositionCluster[0][0]))[i] = (&(rhs.mPositionCluster[0][0]))[i];
   for (Int_t i=0;i<32;i++) (&(mPositionRMSCluster[0][0]))[i] = (&(rhs.mPositionRMSCluster[0][0]))[i];
   for (Int_t i=0;i<32;i++) (&(mLengthCluster[0][0]))[i] = (&(rhs.mLengthCluster[0][0]))[i];
   for (Int_t i=0;i<32;i++) (&(mEnergyCluster[0][0]))[i] = (&(rhs.mEnergyCluster[0][0]))[i];
   for (Int_t i=0;i<32;i++) (&(mXYCluster[0][0]))[i] = (&(rhs.mXYCluster[0][0]))[i];
   for (Int_t i=0;i<32;i++) (&(mQualityCluster[0][0]))[i] = (&(rhs.mQualityCluster[0][0]))[i];
   StMuRpsCollection &modrhs = const_cast<StMuRpsCollection &>( rhs );
   modrhs.mTrackPoints.clear();
   modrhs.mTracks.clear();
}
StMuRpsCollection::~StMuRpsCollection() {
}
#endif // StMuRpsCollection_cxx

#ifndef StMuMtdCollection_cxx
#define StMuMtdCollection_cxx
StMuMtdCollection::StMuMtdCollection() {
}
StMuMtdCollection::StMuMtdCollection(const StMuMtdCollection & rhs)
   : TObject(const_cast<StMuMtdCollection &>( rhs ))
   , mMtdHeader(const_cast<StMuMtdCollection &>( rhs ).mMtdHeader)
   , mMtdHits(const_cast<StMuMtdCollection &>( rhs ).mMtdHits)
   , mMtdRawHits(const_cast<StMuMtdCollection &>( rhs ).mMtdRawHits)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   StMuMtdCollection &modrhs = const_cast<StMuMtdCollection &>( rhs );
   modrhs.mMtdHeader.clear();
   modrhs.mMtdHits.clear();
   modrhs.mMtdRawHits.clear();
}
StMuMtdCollection::~StMuMtdCollection() {
}
#endif // StMuMtdCollection_cxx

#ifndef StV0Mc_cxx
#define StV0Mc_cxx
StV0Mc::StV0Mc() {
}
StV0Mc::StV0Mc(const StV0Mc & rhs)
   : StStrangeMuDst(const_cast<StV0Mc &>( rhs ))
   , StV0I(const_cast<StV0Mc &>( rhs ))
   , mPositiveSimTpcHits(const_cast<StV0Mc &>( rhs ).mPositiveSimTpcHits)
   , mPositiveCommonTpcHits(const_cast<StV0Mc &>( rhs ).mPositiveCommonTpcHits)
   , mNegativeSimTpcHits(const_cast<StV0Mc &>( rhs ).mNegativeSimTpcHits)
   , mNegativeCommonTpcHits(const_cast<StV0Mc &>( rhs ).mNegativeCommonTpcHits)
   , mDecayMode(const_cast<StV0Mc &>( rhs ).mDecayMode)
   , mParentGeantId(const_cast<StV0Mc &>( rhs ).mParentGeantId)
   , mPositiveGeantId(const_cast<StV0Mc &>( rhs ).mPositiveGeantId)
   , mNegativeGeantId(const_cast<StV0Mc &>( rhs ).mNegativeGeantId)
   , mParentMomentumX(const_cast<StV0Mc &>( rhs ).mParentMomentumX)
   , mParentMomentumY(const_cast<StV0Mc &>( rhs ).mParentMomentumY)
   , mParentMomentumZ(const_cast<StV0Mc &>( rhs ).mParentMomentumZ)
   , mPositiveMomentumX(const_cast<StV0Mc &>( rhs ).mPositiveMomentumX)
   , mPositiveMomentumY(const_cast<StV0Mc &>( rhs ).mPositiveMomentumY)
   , mPositiveMomentumZ(const_cast<StV0Mc &>( rhs ).mPositiveMomentumZ)
   , mNegativeMomentumX(const_cast<StV0Mc &>( rhs ).mNegativeMomentumX)
   , mNegativeMomentumY(const_cast<StV0Mc &>( rhs ).mNegativeMomentumY)
   , mNegativeMomentumZ(const_cast<StV0Mc &>( rhs ).mNegativeMomentumZ)
   , mPositionX(const_cast<StV0Mc &>( rhs ).mPositionX)
   , mPositionY(const_cast<StV0Mc &>( rhs ).mPositionY)
   , mPositionZ(const_cast<StV0Mc &>( rhs ).mPositionZ)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StV0Mc::~StV0Mc() {
}
#endif // StV0Mc_cxx

#ifndef StStrangeAssoc_cxx
#define StStrangeAssoc_cxx
StStrangeAssoc::StStrangeAssoc() {
}
StStrangeAssoc::StStrangeAssoc(const StStrangeAssoc & rhs)
   : TObject(const_cast<StStrangeAssoc &>( rhs ))
   , mIndexRecoArray(const_cast<StStrangeAssoc &>( rhs ).mIndexRecoArray)
   , mIndexMcArray(const_cast<StStrangeAssoc &>( rhs ).mIndexMcArray)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StStrangeAssoc::~StStrangeAssoc() {
}
#endif // StStrangeAssoc_cxx

#ifndef StXiMc_cxx
#define StXiMc_cxx
StXiMc::StXiMc() {
}
StXiMc::StXiMc(const StXiMc & rhs)
   : StKinkMc(const_cast<StXiMc &>( rhs ))
   , StXiI(const_cast<StXiMc &>( rhs ))
   , v0(const_cast<StXiMc &>( rhs ).v0)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StXiMc::~StXiMc() {
}
#endif // StXiMc_cxx

#ifndef StKinkMc_cxx
#define StKinkMc_cxx
StKinkMc::StKinkMc() {
}
StKinkMc::StKinkMc(const StKinkMc & rhs)
   : StKinkBase(const_cast<StKinkMc &>( rhs ))
   , mSimTpcHits(const_cast<StKinkMc &>( rhs ).mSimTpcHits)
   , mCommonTpcHits(const_cast<StKinkMc &>( rhs ).mCommonTpcHits)
   , mDecayMode(const_cast<StKinkMc &>( rhs ).mDecayMode)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StKinkMc::~StKinkMc() {
}
#endif // StKinkMc_cxx

#ifndef StMuMcVertex_cxx
#define StMuMcVertex_cxx
StMuMcVertex::StMuMcVertex() {
}
StMuMcVertex::StMuMcVertex(const StMuMcVertex & rhs)
   : TObject(const_cast<StMuMcVertex &>( rhs ))
   , mId(const_cast<StMuMcVertex &>( rhs ).mId)
   , mNoDaughters(const_cast<StMuMcVertex &>( rhs ).mNoDaughters)
   , mIdParTrk(const_cast<StMuMcVertex &>( rhs ).mIdParTrk)
   , mIsInterm(const_cast<StMuMcVertex &>( rhs ).mIsInterm)
   , mTime(const_cast<StMuMcVertex &>( rhs ).mTime)
   , mXyzV(const_cast<StMuMcVertex &>( rhs ).mXyzV)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuMcVertex::~StMuMcVertex() {
}
#endif // StMuMcVertex_cxx

#ifndef StMuMcTrack_cxx
#define StMuMcTrack_cxx
StMuMcTrack::StMuMcTrack() {
}
StMuMcTrack::StMuMcTrack(const StMuMcTrack & rhs)
   : TObject(const_cast<StMuMcTrack &>( rhs ))
   , mGePid(const_cast<StMuMcTrack &>( rhs ).mGePid)
   , mId(const_cast<StMuMcTrack &>( rhs ).mId)
   , mIsShower(const_cast<StMuMcTrack &>( rhs ).mIsShower)
   , mItrmdVertex(const_cast<StMuMcTrack &>( rhs ).mItrmdVertex)
   , mIdVx(const_cast<StMuMcTrack &>( rhs ).mIdVx)
   , mIdVxEnd(const_cast<StMuMcTrack &>( rhs ).mIdVxEnd)
   , mCharge(const_cast<StMuMcTrack &>( rhs ).mCharge)
   , mE(const_cast<StMuMcTrack &>( rhs ).mE)
   , mEta(const_cast<StMuMcTrack &>( rhs ).mEta)
   , mPxyz(const_cast<StMuMcTrack &>( rhs ).mPxyz)
   , mpT(const_cast<StMuMcTrack &>( rhs ).mpT)
   , mPtot(const_cast<StMuMcTrack &>( rhs ).mPtot)
   , mRapidity(const_cast<StMuMcTrack &>( rhs ).mRapidity)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<22;i++) mHits[i] = rhs.mHits[i];
}
StMuMcTrack::~StMuMcTrack() {
}
#endif // StMuMcTrack_cxx

#ifndef StMuEmcTowerData_cxx
#define StMuEmcTowerData_cxx
StMuEmcTowerData::StMuEmcTowerData() {
}
StMuEmcTowerData::StMuEmcTowerData(const StMuEmcTowerData & rhs)
   : TObject(const_cast<StMuEmcTowerData &>( rhs ))
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<4800;i++) mTowerADC[i] = rhs.mTowerADC[i];
   for (Int_t i=0;i<720;i++) mEndcapTowerADC[i] = rhs.mEndcapTowerADC[i];
   for (Int_t i=0;i<30;i++) mBTowCrateFlags[i] = rhs.mBTowCrateFlags[i];
   for (Int_t i=0;i<8;i++) mBSmdCrateFlags[i] = rhs.mBSmdCrateFlags[i];
   for (Int_t i=0;i<4;i++) mBPrsCrateFlags[i] = rhs.mBPrsCrateFlags[i];
   for (Int_t i=0;i<6;i++) mETowCrateFlags[i] = rhs.mETowCrateFlags[i];
   for (Int_t i=0;i<36;i++) mESmdCrateFlags[i] = rhs.mESmdCrateFlags[i];
   for (Int_t i=0;i<12;i++) mEPrsCrateFlags[i] = rhs.mEPrsCrateFlags[i];
}
StMuEmcTowerData::~StMuEmcTowerData() {
}
#endif // StMuEmcTowerData_cxx

#ifndef StMuEmcHit_cxx
#define StMuEmcHit_cxx
StMuEmcHit::StMuEmcHit() {
}
StMuEmcHit::StMuEmcHit(const StMuEmcHit & rhs)
   : TObject(const_cast<StMuEmcHit &>( rhs ))
   , mEnergy(const_cast<StMuEmcHit &>( rhs ).mEnergy)
   , mId(const_cast<StMuEmcHit &>( rhs ).mId)
   , mAdc(const_cast<StMuEmcHit &>( rhs ).mAdc)
   , mCalType(const_cast<StMuEmcHit &>( rhs ).mCalType)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuEmcHit::~StMuEmcHit() {
}
#endif // StMuEmcHit_cxx

#ifndef StMuPmdHit_cxx
#define StMuPmdHit_cxx
StMuPmdHit::StMuPmdHit() {
}
StMuPmdHit::StMuPmdHit(const StMuPmdHit & rhs)
   : TObject(const_cast<StMuPmdHit &>( rhs ))
   , mSuperModule(const_cast<StMuPmdHit &>( rhs ).mSuperModule)
   , mSubDetector(const_cast<StMuPmdHit &>( rhs ).mSubDetector)
   , mRow(const_cast<StMuPmdHit &>( rhs ).mRow)
   , mCol(const_cast<StMuPmdHit &>( rhs ).mCol)
   , mEnergy(const_cast<StMuPmdHit &>( rhs ).mEnergy)
   , mADC(const_cast<StMuPmdHit &>( rhs ).mADC)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuPmdHit::~StMuPmdHit() {
}
#endif // StMuPmdHit_cxx

#ifndef StMuPmdCluster_cxx
#define StMuPmdCluster_cxx
StMuPmdCluster::StMuPmdCluster() {
}
StMuPmdCluster::StMuPmdCluster(const StMuPmdCluster & rhs)
   : TObject(const_cast<StMuPmdCluster &>( rhs ))
   , mSuperModule(const_cast<StMuPmdCluster &>( rhs ).mSuperModule)
   , mNcell(const_cast<StMuPmdCluster &>( rhs ).mNcell)
   , mEta(const_cast<StMuPmdCluster &>( rhs ).mEta)
   , mPhi(const_cast<StMuPmdCluster &>( rhs ).mPhi)
   , mSigma(const_cast<StMuPmdCluster &>( rhs ).mSigma)
   , mEnergy(const_cast<StMuPmdCluster &>( rhs ).mEnergy)
   , mEnergyPID(const_cast<StMuPmdCluster &>( rhs ).mEnergyPID)
   , mPID(const_cast<StMuPmdCluster &>( rhs ).mPID)
   , mMcPID(const_cast<StMuPmdCluster &>( rhs ).mMcPID)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuPmdCluster::~StMuPmdCluster() {
}
#endif // StMuPmdCluster_cxx

#ifndef StMuFmsHit_cxx
#define StMuFmsHit_cxx
StMuFmsHit::StMuFmsHit() {
}
StMuFmsHit::StMuFmsHit(const StMuFmsHit & rhs)
   : TObject(const_cast<StMuFmsHit &>( rhs ))
   , mDetectorId(const_cast<StMuFmsHit &>( rhs ).mDetectorId)
   , mChannel(const_cast<StMuFmsHit &>( rhs ).mChannel)
   , mQTCrtSlotCh(const_cast<StMuFmsHit &>( rhs ).mQTCrtSlotCh)
   , mAdc(const_cast<StMuFmsHit &>( rhs ).mAdc)
   , mTdc(const_cast<StMuFmsHit &>( rhs ).mTdc)
   , mEnergy(const_cast<StMuFmsHit &>( rhs ).mEnergy)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuFmsHit::~StMuFmsHit() {
}
#endif // StMuFmsHit_cxx

#ifndef StMuFmsCluster_cxx
#define StMuFmsCluster_cxx
StMuFmsCluster::StMuFmsCluster() {
}
StMuFmsCluster::StMuFmsCluster(const StMuFmsCluster & rhs)
   : TObject(const_cast<StMuFmsCluster &>( rhs ))
   , mDetectorId(const_cast<StMuFmsCluster &>( rhs ).mDetectorId)
   , mCategory(const_cast<StMuFmsCluster &>( rhs ).mCategory)
   , mEnergy(const_cast<StMuFmsCluster &>( rhs ).mEnergy)
   , mX(const_cast<StMuFmsCluster &>( rhs ).mX)
   , mY(const_cast<StMuFmsCluster &>( rhs ).mY)
   , mSigmaMin(const_cast<StMuFmsCluster &>( rhs ).mSigmaMin)
   , mSigmaMax(const_cast<StMuFmsCluster &>( rhs ).mSigmaMax)
   , mChi2Ndf1Photon(const_cast<StMuFmsCluster &>( rhs ).mChi2Ndf1Photon)
   , mChi2Ndf2Photon(const_cast<StMuFmsCluster &>( rhs ).mChi2Ndf2Photon)
   , mId(const_cast<StMuFmsCluster &>( rhs ).mId)
   , mHits(const_cast<StMuFmsCluster &>( rhs ).mHits)
   , mPhotons(const_cast<StMuFmsCluster &>( rhs ).mPhotons)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuFmsCluster::~StMuFmsCluster() {
}
#endif // StMuFmsCluster_cxx

#ifndef StMuFmsPoint_cxx
#define StMuFmsPoint_cxx
StMuFmsPoint::StMuFmsPoint() {
}
StMuFmsPoint::StMuFmsPoint(const StMuFmsPoint & rhs)
   : TObject(const_cast<StMuFmsPoint &>( rhs ))
   , mDetectorId(const_cast<StMuFmsPoint &>( rhs ).mDetectorId)
   , mEnergy(const_cast<StMuFmsPoint &>( rhs ).mEnergy)
   , mX(const_cast<StMuFmsPoint &>( rhs ).mX)
   , mY(const_cast<StMuFmsPoint &>( rhs ).mY)
   , mId(const_cast<StMuFmsPoint &>( rhs ).mId)
   , mXYZ(const_cast<StMuFmsPoint &>( rhs ).mXYZ)
   , mCluster(const_cast<StMuFmsPoint &>( rhs ).mCluster)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuFmsPoint::~StMuFmsPoint() {
}
#endif // StMuFmsPoint_cxx

#ifndef StMuFmsInfo_cxx
#define StMuFmsInfo_cxx
StMuFmsInfo::StMuFmsInfo() {
}
StMuFmsInfo::StMuFmsInfo(const StMuFmsInfo & rhs)
   : TObject(const_cast<StMuFmsInfo &>( rhs ))
   , mFmsReconstructionFlag(const_cast<StMuFmsInfo &>( rhs ).mFmsReconstructionFlag)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuFmsInfo::~StMuFmsInfo() {
}
#endif // StMuFmsInfo_cxx

#ifndef StMuTofHit_cxx
#define StMuTofHit_cxx
StMuTofHit::StMuTofHit() {
}
StMuTofHit::StMuTofHit(const StMuTofHit & rhs)
   : StObject(const_cast<StMuTofHit &>( rhs ))
   , mIconf(const_cast<StMuTofHit &>( rhs ).mIconf)
   , mTrayIndex(const_cast<StMuTofHit &>( rhs ).mTrayIndex)
   , mModuleIndex(const_cast<StMuTofHit &>( rhs ).mModuleIndex)
   , mCellIndex(const_cast<StMuTofHit &>( rhs ).mCellIndex)
   , mDaqIndex(const_cast<StMuTofHit &>( rhs ).mDaqIndex)
   , mADC(const_cast<StMuTofHit &>( rhs ).mADC)
   , mTimeOfFlight(const_cast<StMuTofHit &>( rhs ).mTimeOfFlight)
   , mPathLength(const_cast<StMuTofHit &>( rhs ).mPathLength)
   , mBeta(const_cast<StMuTofHit &>( rhs ).mBeta)
   , mAssociatedTrackId(const_cast<StMuTofHit &>( rhs ).mAssociatedTrackId)
   , mProjectedPoint(const_cast<StMuTofHit &>( rhs ).mProjectedPoint)
   , mTOFExpectedAsElectron(const_cast<StMuTofHit &>( rhs ).mTOFExpectedAsElectron)
   , mTOFExpectedAsPion(const_cast<StMuTofHit &>( rhs ).mTOFExpectedAsPion)
   , mTOFExpectedAsKaon(const_cast<StMuTofHit &>( rhs ).mTOFExpectedAsKaon)
   , mTOFExpectedAsProton(const_cast<StMuTofHit &>( rhs ).mTOFExpectedAsProton)
   , mSigmaElectron(const_cast<StMuTofHit &>( rhs ).mSigmaElectron)
   , mSigmaPion(const_cast<StMuTofHit &>( rhs ).mSigmaPion)
   , mSigmaKaon(const_cast<StMuTofHit &>( rhs ).mSigmaKaon)
   , mSigmaProton(const_cast<StMuTofHit &>( rhs ).mSigmaProton)
   , mParticleHypothesis(const_cast<StMuTofHit &>( rhs ).mParticleHypothesis)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuTofHit::~StMuTofHit() {
}
#endif // StMuTofHit_cxx

#ifndef StTofData_cxx
#define StTofData_cxx
StTofData::StTofData() {
}
StTofData::StTofData(const StTofData & rhs)
   : StObject(const_cast<StTofData &>( rhs ))
   , mDataIndex(const_cast<StTofData &>( rhs ).mDataIndex)
   , mAdc(const_cast<StTofData &>( rhs ).mAdc)
   , mTdc(const_cast<StTofData &>( rhs ).mTdc)
   , mTc(const_cast<StTofData &>( rhs ).mTc)
   , mSc(const_cast<StTofData &>( rhs ).mSc)
   , mLeadingTdc(const_cast<StTofData &>( rhs ).mLeadingTdc)
   , mTrailingTdc(const_cast<StTofData &>( rhs ).mTrailingTdc)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StTofData::~StTofData() {
}
#endif // StTofData_cxx

#ifndef StTofRawData_cxx
#define StTofRawData_cxx
StTofRawData::StTofRawData() {
}
StTofRawData::StTofRawData(const StTofRawData & rhs)
   : StObject(const_cast<StTofRawData &>( rhs ))
   , mLeTeFlag(const_cast<StTofRawData &>( rhs ).mLeTeFlag)
   , mTray(const_cast<StTofRawData &>( rhs ).mTray)
   , mChannel(const_cast<StTofRawData &>( rhs ).mChannel)
   , mTdc(const_cast<StTofRawData &>( rhs ).mTdc)
   , mTriggertime(const_cast<StTofRawData &>( rhs ).mTriggertime)
   , mQuality(const_cast<StTofRawData &>( rhs ).mQuality)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StTofRawData::~StTofRawData() {
}
#endif // StTofRawData_cxx

#ifndef StMuBTofHit_cxx
#define StMuBTofHit_cxx
StMuBTofHit::StMuBTofHit() {
}
StMuBTofHit::StMuBTofHit(const StMuBTofHit & rhs)
   : StObject(const_cast<StMuBTofHit &>( rhs ))
   , mTray(const_cast<StMuBTofHit &>( rhs ).mTray)
   , mModule(const_cast<StMuBTofHit &>( rhs ).mModule)
   , mCell(const_cast<StMuBTofHit &>( rhs ).mCell)
   , mLeadingEdgeTime(const_cast<StMuBTofHit &>( rhs ).mLeadingEdgeTime)
   , mTrailingEdgeTime(const_cast<StMuBTofHit &>( rhs ).mTrailingEdgeTime)
   , mAssociatedTrackId(const_cast<StMuBTofHit &>( rhs ).mAssociatedTrackId)
   , mIndex2Primary(const_cast<StMuBTofHit &>( rhs ).mIndex2Primary)
   , mIndex2Global(const_cast<StMuBTofHit &>( rhs ).mIndex2Global)
   , mIdTruth(const_cast<StMuBTofHit &>( rhs ).mIdTruth)
   , mQuality(const_cast<StMuBTofHit &>( rhs ).mQuality)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuBTofHit::~StMuBTofHit() {
}
#endif // StMuBTofHit_cxx

#ifndef StBTofRawHit_cxx
#define StBTofRawHit_cxx
StBTofRawHit::StBTofRawHit() {
}
StBTofRawHit::StBTofRawHit(const StBTofRawHit & rhs)
   : StObject(const_cast<StBTofRawHit &>( rhs ))
   , mFlag(const_cast<StBTofRawHit &>( rhs ).mFlag)
   , mTray(const_cast<StBTofRawHit &>( rhs ).mTray)
   , mChannel(const_cast<StBTofRawHit &>( rhs ).mChannel)
   , mTdc(const_cast<StBTofRawHit &>( rhs ).mTdc)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StBTofRawHit::~StBTofRawHit() {
}
#endif // StBTofRawHit_cxx

#ifndef StBTofHeader_cxx
#define StBTofHeader_cxx
StBTofHeader::StBTofHeader() {
}
StBTofHeader::StBTofHeader(const StBTofHeader & rhs)
   : StObject(const_cast<StBTofHeader &>( rhs ))
   , mTStart(const_cast<StBTofHeader &>( rhs ).mTStart)
   , mTStartErr(const_cast<StBTofHeader &>( rhs ).mTStartErr)
   , mTDiff(const_cast<StBTofHeader &>( rhs ).mTDiff)
   , mNTzero(const_cast<StBTofHeader &>( rhs ).mNTzero)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<4;i++) mFiberHeader[i] = rhs.mFiberHeader[i];
   for (Int_t i=0;i<4;i++) mFiberTriggerWord[i] = rhs.mFiberTriggerWord[i];
   for (Int_t i=0;i<2;i++) mVpdHitPattern[i] = rhs.mVpdHitPattern[i];
   for (Int_t i=0;i<20;i++) mVpdVz[i] = rhs.mVpdVz[i];
   for (Int_t i=0;i<38;i++) (&(mVpdTime[0][0]))[i] = (&(rhs.mVpdTime[0][0]))[i];
   for (Int_t i=0;i<4;i++) mTriggerTime[i] = rhs.mTriggerTime[i];
}
StBTofHeader::~StBTofHeader() {
}
#endif // StBTofHeader_cxx

#ifndef StMuEpdHit_cxx
#define StMuEpdHit_cxx
StMuEpdHit::StMuEpdHit() {
}
StMuEpdHit::StMuEpdHit(const StMuEpdHit & rhs)
   : StObject(const_cast<StMuEpdHit &>( rhs ))
   , mId(const_cast<StMuEpdHit &>( rhs ).mId)
   , mQTdata(const_cast<StMuEpdHit &>( rhs ).mQTdata)
   , mnMIP(const_cast<StMuEpdHit &>( rhs ).mnMIP)
   , mTruthId(const_cast<StMuEpdHit &>( rhs ).mTruthId)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuEpdHit::~StMuEpdHit() {
}
#endif // StMuEpdHit_cxx

#ifndef StMuMtdHit_cxx
#define StMuMtdHit_cxx
StMuMtdHit::StMuMtdHit() {
}
StMuMtdHit::StMuMtdHit(const StMuMtdHit & rhs)
   : TObject(const_cast<StMuMtdHit &>( rhs ))
   , mBackLeg(const_cast<StMuMtdHit &>( rhs ).mBackLeg)
   , mModule(const_cast<StMuMtdHit &>( rhs ).mModule)
   , mCell(const_cast<StMuMtdHit &>( rhs ).mCell)
   , mLeadingEdgeTime(const_cast<StMuMtdHit &>( rhs ).mLeadingEdgeTime)
   , mTrailingEdgeTime(const_cast<StMuMtdHit &>( rhs ).mTrailingEdgeTime)
   , mIdTruth(const_cast<StMuMtdHit &>( rhs ).mIdTruth)
   , mQuality(const_cast<StMuMtdHit &>( rhs ).mQuality)
   , mTrackKey(const_cast<StMuMtdHit &>( rhs ).mTrackKey)
   , mIndex2Primary(const_cast<StMuMtdHit &>( rhs ).mIndex2Primary)
   , mIndex2Global(const_cast<StMuMtdHit &>( rhs ).mIndex2Global)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuMtdHit::~StMuMtdHit() {
}
#endif // StMuMtdHit_cxx

#ifndef StMuMtdRawHit_cxx
#define StMuMtdRawHit_cxx
StMuMtdRawHit::StMuMtdRawHit() {
}
StMuMtdRawHit::StMuMtdRawHit(const StMuMtdRawHit & rhs)
   : TObject(const_cast<StMuMtdRawHit &>( rhs ))
   , mFlag(const_cast<StMuMtdRawHit &>( rhs ).mFlag)
   , mBackLeg(const_cast<StMuMtdRawHit &>( rhs ).mBackLeg)
   , mChannel(const_cast<StMuMtdRawHit &>( rhs ).mChannel)
   , mTdc(const_cast<StMuMtdRawHit &>( rhs ).mTdc)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuMtdRawHit::~StMuMtdRawHit() {
}
#endif // StMuMtdRawHit_cxx

#ifndef StMuMtdHeader_cxx
#define StMuMtdHeader_cxx
StMuMtdHeader::StMuMtdHeader() {
}
StMuMtdHeader::StMuMtdHeader(const StMuMtdHeader & rhs)
   : TObject(const_cast<StMuMtdHeader &>( rhs ))
   , mFiberHeader1(const_cast<StMuMtdHeader &>( rhs ).mFiberHeader1)
   , mFiberHeader2(const_cast<StMuMtdHeader &>( rhs ).mFiberHeader2)
   , mFiberTriggerWord1(const_cast<StMuMtdHeader &>( rhs ).mFiberTriggerWord1)
   , mFiberTriggerWord2(const_cast<StMuMtdHeader &>( rhs ).mFiberTriggerWord2)
   , mTriggerTime1(const_cast<StMuMtdHeader &>( rhs ).mTriggerTime1)
   , mTriggerTime2(const_cast<StMuMtdHeader &>( rhs ).mTriggerTime2)
   , mShouldHaveRejectEvent(const_cast<StMuMtdHeader &>( rhs ).mShouldHaveRejectEvent)
   , mTpcSectorMask(const_cast<StMuMtdHeader &>( rhs ).mTpcSectorMask)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuMtdHeader::~StMuMtdHeader() {
}
#endif // StMuMtdHeader_cxx

#ifndef StMuFgtStrip_cxx
#define StMuFgtStrip_cxx
StMuFgtStrip::StMuFgtStrip() {
}
StMuFgtStrip::StMuFgtStrip(const StMuFgtStrip & rhs)
   : TObject(const_cast<StMuFgtStrip &>( rhs ))
   , mGeoId(const_cast<StMuFgtStrip &>( rhs ).mGeoId)
   , mAdcStartIdx(const_cast<StMuFgtStrip &>( rhs ).mAdcStartIdx)
   , mNumSavedTimeBins(const_cast<StMuFgtStrip &>( rhs ).mNumSavedTimeBins)
   , mClusterSeedType(const_cast<StMuFgtStrip &>( rhs ).mClusterSeedType)
   , mCharge(const_cast<StMuFgtStrip &>( rhs ).mCharge)
   , mChargeUncert(const_cast<StMuFgtStrip &>( rhs ).mChargeUncert)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuFgtStrip::~StMuFgtStrip() {
}
#endif // StMuFgtStrip_cxx

#ifndef StMuFgtCluster_cxx
#define StMuFgtCluster_cxx
StMuFgtCluster::StMuFgtCluster() {
}
StMuFgtCluster::StMuFgtCluster(const StMuFgtCluster & rhs)
   : TObject(const_cast<StMuFgtCluster &>( rhs ))
   , mCentralStripGeoId(const_cast<StMuFgtCluster &>( rhs ).mCentralStripGeoId)
   , mFirstStripAssociationIdx(const_cast<StMuFgtCluster &>( rhs ).mFirstStripAssociationIdx)
   , mMaxTimeBin(const_cast<StMuFgtCluster &>( rhs ).mMaxTimeBin)
   , mMaxAdc(const_cast<StMuFgtCluster &>( rhs ).mMaxAdc)
   , mNumStrips(const_cast<StMuFgtCluster &>( rhs ).mNumStrips)
   , mCharge(const_cast<StMuFgtCluster &>( rhs ).mCharge)
   , mChargeUncert(const_cast<StMuFgtCluster &>( rhs ).mChargeUncert)
   , mR(const_cast<StMuFgtCluster &>( rhs ).mR)
   , mErrR(const_cast<StMuFgtCluster &>( rhs ).mErrR)
   , mPhi(const_cast<StMuFgtCluster &>( rhs ).mPhi)
   , mErrPhi(const_cast<StMuFgtCluster &>( rhs ).mErrPhi)
   , mEvenOddChargeAsy(const_cast<StMuFgtCluster &>( rhs ).mEvenOddChargeAsy)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuFgtCluster::~StMuFgtCluster() {
}
#endif // StMuFgtCluster_cxx

#ifndef StMuFgtStripAssociation_cxx
#define StMuFgtStripAssociation_cxx
StMuFgtStripAssociation::StMuFgtStripAssociation() {
}
StMuFgtStripAssociation::StMuFgtStripAssociation(const StMuFgtStripAssociation & rhs)
   : TObject(const_cast<StMuFgtStripAssociation &>( rhs ))
   , mClusIdx(const_cast<StMuFgtStripAssociation &>( rhs ).mClusIdx)
   , mStripIdx(const_cast<StMuFgtStripAssociation &>( rhs ).mStripIdx)
   , mWeight(const_cast<StMuFgtStripAssociation &>( rhs ).mWeight)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuFgtStripAssociation::~StMuFgtStripAssociation() {
}
#endif // StMuFgtStripAssociation_cxx

#ifndef StMuFgtAdc_cxx
#define StMuFgtAdc_cxx
StMuFgtAdc::StMuFgtAdc() {
}
StMuFgtAdc::StMuFgtAdc(const StMuFgtAdc & rhs)
   : TObject(const_cast<StMuFgtAdc &>( rhs ))
   , mAdc(const_cast<StMuFgtAdc &>( rhs ).mAdc)
   , mTimeBin(const_cast<StMuFgtAdc &>( rhs ).mTimeBin)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StMuFgtAdc::~StMuFgtAdc() {
}
#endif // StMuFgtAdc_cxx

#ifndef StTriggerData2016_cxx
#define StTriggerData2016_cxx
StTriggerData2016::StTriggerData2016() {
   mData = 0;
}
StTriggerData2016::StTriggerData2016(const StTriggerData2016 & rhs)
   : StTriggerData(const_cast<StTriggerData2016 &>( rhs ))
   , mData(const_cast<StTriggerData2016 &>( rhs ).mData)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   StTriggerData2016 &modrhs = const_cast<StTriggerData2016 &>( rhs );
   modrhs.mData = 0;
   for (Int_t i=0;i<5632;i++) (&(mxq[0][0][0]))[i] = (&(rhs.mxq[0][0][0]))[i];
   for (Int_t i=0;i<5632;i++) (&(feq[0][0][0]))[i] = (&(rhs.feq[0][0][0]))[i];
   for (Int_t i=0;i<5632;i++) (&(bbq[0][0][0]))[i] = (&(rhs.bbq[0][0][0]))[i];
   for (Int_t i=0;i<5632;i++) (&(qt1[0][0][0]))[i] = (&(rhs.qt1[0][0][0]))[i];
   for (Int_t i=0;i<5632;i++) (&(qt2[0][0][0]))[i] = (&(rhs.qt2[0][0][0]))[i];
   for (Int_t i=0;i<5632;i++) (&(qt3[0][0][0]))[i] = (&(rhs.qt3[0][0][0]))[i];
   for (Int_t i=0;i<5632;i++) (&(tmxq[0][0][0]))[i] = (&(rhs.tmxq[0][0][0]))[i];
   for (Int_t i=0;i<5632;i++) (&(tfeq[0][0][0]))[i] = (&(rhs.tfeq[0][0][0]))[i];
   for (Int_t i=0;i<5632;i++) (&(tbbq[0][0][0]))[i] = (&(rhs.tbbq[0][0][0]))[i];
   for (Int_t i=0;i<5632;i++) (&(tqt1[0][0][0]))[i] = (&(rhs.tqt1[0][0][0]))[i];
   for (Int_t i=0;i<5632;i++) (&(tqt2[0][0][0]))[i] = (&(rhs.tqt2[0][0][0]))[i];
   for (Int_t i=0;i<5632;i++) (&(tqt3[0][0][0]))[i] = (&(rhs.tqt3[0][0][0]))[i];
}
StTriggerData2016::~StTriggerData2016() {
   delete mData;   mData = 0;
}
#endif // StTriggerData2016_cxx

#ifndef StTriggerData_cxx
#define StTriggerData_cxx
StTriggerData::StTriggerData() {
}
StTriggerData::StTriggerData(const StTriggerData & rhs)
   : StObject(const_cast<StTriggerData &>( rhs ))
   , mYear(const_cast<StTriggerData &>( rhs ).mYear)
   , mZdcVertexZ(const_cast<StTriggerData &>( rhs ).mZdcVertexZ)
   , mRun(const_cast<StTriggerData &>( rhs ).mRun)
   , mErrorFlag(const_cast<StTriggerData &>( rhs ).mErrorFlag)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
StTriggerData::~StTriggerData() {
}
#endif // StTriggerData_cxx

#ifndef TriggerDataBlk2016_cxx
#define TriggerDataBlk2016_cxx
TriggerDataBlk2016::TriggerDataBlk2016() {
}
TriggerDataBlk2016::TriggerDataBlk2016(const TriggerDataBlk2016 & rhs)
   : FormatVersion(const_cast<TriggerDataBlk2016 &>( rhs ).FormatVersion)
   , totalTriggerLength(const_cast<TriggerDataBlk2016 &>( rhs ).totalTriggerLength)
   , eventNumber(const_cast<TriggerDataBlk2016 &>( rhs ).eventNumber)
   , EventDesc_ofl(const_cast<TriggerDataBlk2016 &>( rhs ).EventDesc_ofl)
   , L1_DSM_ofl(const_cast<TriggerDataBlk2016 &>( rhs ).L1_DSM_ofl)
   , Summary_ofl(const_cast<TriggerDataBlk2016 &>( rhs ).Summary_ofl)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   for (Int_t i=0;i<20;i++) MainX[i] = rhs.MainX[i];
   for (Int_t i=0;i<10;i++) PrePostList[i] = rhs.PrePostList[i];
   for (Int_t i=0;i<30724;i++) raw_data[i] = rhs.raw_data[i];
}
TriggerDataBlk2016::~TriggerDataBlk2016() {
}
#endif // TriggerDataBlk2016_cxx

#ifndef TrgOfflen2016_cxx
#define TrgOfflen2016_cxx
TrgOfflen2016::TrgOfflen2016() {
}
TrgOfflen2016::TrgOfflen2016(const TrgOfflen2016 & rhs)
   : offset(const_cast<TrgOfflen2016 &>( rhs ).offset)
   , length(const_cast<TrgOfflen2016 &>( rhs ).length)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
TrgOfflen2016::~TrgOfflen2016() {
}
#endif // TrgOfflen2016_cxx

