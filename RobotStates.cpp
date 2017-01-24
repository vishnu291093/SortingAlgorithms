#include "RobotStates.h"



argos::UInt16 CRobotCommunication::Convert8to16unsigned(argos::UInt16 upper,argos::UInt16 lower)
{

    argos::UInt16 newvalue = (upper <<8) | lower;
    return newvalue;

}


argos::SInt16 CRobotCommunication::Convert8to16signed(argos::SInt16 upper ,argos::SInt16 lower)
{
    if(upper < 0)
    {
    upper = 0 - upper;
    argos::SInt16 newvalue = (upper <<8) | lower;
    newvalue = - newvalue;
    return newvalue;
    }
    else
    {
    argos::SInt16 newvalue = (upper <<8) | lower;
    return newvalue;

    }

}


void CRobotCommunication::Convert16to8unsigned( argos::UInt16 u_number1,argos::UInt16& un_upper,argos::UInt16 & un_lower)
{
    argos::UInt16 temp1= u_number1;
    temp1 = temp1 <<8;
    argos::UInt16 uppertemp = 255;
    un_upper = temp1 & uppertemp;
    un_lower = u_number1 & uppertemp;
}


void CRobotCommunication::EmitData(argos::UInt16 * un_Transmit_Array)
{
    {
    CByteArray cBuffer;
    for(argos::UInt16 temp1=0;temp1<m_uLengthBuffer;temp1++)
    {
        cBuffer << static_cast<UInt8>(un_Transmit_Array[temp1]);
    }
    m_pcRABA->SetData(cBuffer);
}

void CRobotCommunication::ReceiveData()
{
    const CCI_RangeAndBearingSensor::TReadings& tReadings=m_pcRABS->GetReadings();
    for(argos::UInt16 temp = 0; temp < tReadings.size();temp++)
    {
        if(tReadings[temp].Data[2] == 1)
        {



        }
      else if (tReadings[temp].Data[2] == 2)
      {





      }
      else if (tReadings[temp].Data[2] == 3)
      {




      }
        else if (tReadings[temp].Data[2] == 4)
      {




      }
        else if (tReadings[temp].Data[2] == 5)
      {




      }

        else if (tReadings[temp].Data[2] == 6)
      {




      }


      /*
       std::unique_ptr<argos::UInt16[]> data(new argos::UInt16[m_uLengthBuffer]);
       for(argos::UInt16 temp2 = 0; temp < m_uLengthBuffer;temp++)
       {
            data[temp] = tReadings[temp].Data[temp2]
       }
       ReceivedData.push(data);

    }
*/
}
}


void CRobotCommunication::FindParent()
{
    argos::UInt16 unData[m_uLengthBuffer];
    Convert16to8unsigned(m_sRobotID,unData[0],unData[1]);
    unData[2]=3;
    Convert16to8unsigned(m_sRobotParent,unData[3],unData[4]);
    unData[5]=0;
    unData[6]=0;
    unData[7]=0;
    unData[8]=0;
    unData[9]=100;
    EmitData(unData);
}


