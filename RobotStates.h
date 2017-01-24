#ifndef RobotBehaviorStates
#define RobotBehaviorStates


#include<queue>
using namespace argos;




CRobotMainBehavior{

public:
    CCI_LEDsActuator* m_pcLEDs;
    argos::UInt16 m_sRobotID;
    argos::UInt16 m_sRobotParent;
    CRobotMainBehavior(CCI_LEDsActuator* pc_LEDs,std::string s_Robot_ID, std::string s_Robot_Parent)
    {
        m_sRobotID=atoi(s_Robot_ID.c_str());
        m_sRobotParent = atoi(s_Robot_Parent.c_str());
        m_pcLEDs = pc_LEDs;
    }

    CRobotMainBehavior()
    {


    }
    ~CRobotMainBehavior()
    {




    }
    virtual void updatestate() = 0;
    void ChangeColor( bool Status);


};

class CRobotCommunication{

public:

    CCI_RangeAndBearingActuator*  m_pcRABA;
    CCI_RangeAndBearingSensor* m_pcRABS;
    argos::UInt16 m_uLengthBuffer;
    argos::UInt32 m_unLengthToBeTransmitted;
    argos::UInt16 m_unLengthRemainder;
    bool ParentOnline=false;
    std::queue< std::unique_ptr<argos::UInt16[]> > ReceivedData;
    CRobotCommunication(CCI_RangeAndBearingActuator*  pc_RABA, CCI_RangeAndBearingSensor* pc_RABS,argos::UInt16 un_length_buffer)
    {
        m_pcRABA=pc_RABA;
        m_pcRABS=pc_RABS;
        m_uLengthBuffer = un_length_buffer;

    }
    ~CRobotCommunication()
    {

    }

    argos::UInt16 Convert8to16unsigned(argos::UInt16 ,argos::UInt16 );
    argos::SInt16 Convert8to16signed(argos::SInt16 ,argos::SInt16 );
    void Convert16to8unsigned();
    void EmitData(argos::UInt16 *);
    void ReceiveData();
    void FindParent();  //this function is for seeing whether the parent is busy or not




};

class MasterRobot:public CRobotMainBehavior, public CRobotCommunication
{

public:
    MasterRobot(CCI_RangeAndBearingActuator*  pc_RABA, CCI_RangeAndBearingSensor* pc_RABS,argos::UInt16 un_length_buffer,CCI_LEDsActuator* m_pcLEDs, std::string m_sRobotID,std::string m_sRobotParent):CRobotCommunication(pc_RABA,pc_RABS,un_length_buffer),CRobotMainBehavior(m_pcLEDs,m_sRobotID,m_sRobotParent)
    {

    }
    ~MasterRobot()
    {

    }


};

class ChainRobot:public CRobotMainBehavior, public CRobotCommunication
{

public:
    ChainRobot(CCI_RangeAndBearingActuator*  pc_RABA, CCI_RangeAndBearingSensor* pc_RABS,argos::UInt16 un_length_buffer,CCI_LEDsActuator* m_pcLEDs, std::string m_sRobotID,std::string m_sRobotParent):CRobotCommunication(pc_RABA,pc_RABS,un_length_buffer),CRobotMainBehavior(m_pcLEDs, m_sRobotID,m_sRobotParent)

    {

    }
    ~ChainRobot()
    {

    }


};

class TransmitRobot:public CRobotMainBehavior, public CRobotCommunication
{

public:
    TransmitRobot(CCI_RangeAndBearingActuator*  pc_RABA, CCI_RangeAndBearingSensor* pc_RABS,argos::UInt16 un_length_buffer,CCI_LEDsActuator* m_pcLEDs,std::string m_sRobotID,std::string m_sRobotParent):CRobotCommunication(pc_RABA,pc_RABS,un_length_buffer),CRobotMainBehavior(m_pcLEDs, m_sRobotID,m_sRobotParent)

    {

    }
    ~TransmitRobot()
    {

    }


};

class MappingRobot:public CRobotMainBehavior
{

public:
    bool m_bParentOnline;
    bool m_bMappingCompleted;
    MappingRobot(CCI_LEDsActuator* m_pcLEDs, std::string m_sRobotID,std::string m_sRobotParent):CRobotMainBehavior(m_pcLEDs, m_sRobotID,m_sRobotParent)
    {
        m_bParentOnline=false;
        m_bMappingCompleted=false;

    }
    ~MappingRobot()

    {

    }


};




#endif
