#ifndef MINERSKID_H
#define MINERSKID_H
//------------------------------------------------------------------------
//
//  Name: MinersWife.h
//
//  Desc: class to implement Miner Bob's wife.
//
//  Author: Mat Buckland 2003 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------

#include <string>

#include "fsm/State.h"
#include "BaseGameEntity.h"
#include "Locations.h"
#include "MinersKidOwnedStates.h"
#include "misc/ConsoleUtils.h"
#include "Miner.h"
#include "MinersWife.h"
#include "fsm/StateMachine.h"
#include "misc/Utils.h"



class MinersKid : public BaseGameEntity
{
private:

  //an instance of the state machine class
  StateMachine<MinersKid>* m_pStateMachine;

  location_type   m_Location;

  //is she presently crying?
  bool            m_bCrying;


public:

  MinersKid(int id):m_Location(shack),
                     m_bCrying(false),
                     BaseGameEntity(id)
                                        
  {
    //set up the state machine
    m_pStateMachine = new StateMachine<MinersKid>(this);

    m_pStateMachine->SetCurrentState(DoHomeWork::Instance());

    m_pStateMachine->SetGlobalState(KidsGlobalState::Instance());
  }

  ~MinersKid(){delete m_pStateMachine;}


  //this must be implemented
  void          Update();

  //so must this
  virtual bool  HandleMessage(const Telegram& msg);

  StateMachine<MinersKid>* GetFSM()const{return m_pStateMachine;}

  //----------------------------------------------------accessors
  location_type Location()const{return m_Location;}
  void          ChangeLocation(location_type loc){m_Location=loc;}

  bool          Cooking()const{return m_bCrying;}
  void          SetCrying(bool val){m_bCrying = val;}
   
};

#endif
