
// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/* 
 * Copyright (C) 2014 RobotCub Consortium, European Commission FP7 Project
 * Author: Uriel Martinez
 * email: uriel.marherz@gmail.com
 * website: www.robotcub.org
 * Permission is granted to copy, distribute, and/or modify this program
 * under the terms of the GNU General Public License, version 2 or any
 * later version published by the Free Software Foundation.
 * *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details
*/

#include <yarp/os/Network.h>
#include <yarp/os/Time.h>
#include <txzy.h>

using namespace yarp;
using namespace yarp::os;

int main(int argc, char *argv[])
{
	Network yarp;

	if (!yarp.checkNetwork())
	{
		cout << endl << "ERROR: yarpserver not found" << endl;
		return false;
	}

    Txzy *myTxzy;

    myTxzy = new Txzy("/dev/ttyACM0",9600,"none",8,1);

    cout << "Opening port" << endl;
    myTxzy->openPort();

    for( int i = 0; i < 5; i++ )
    {
        cout << "----------------------" << endl;
        cout << "Moving command single axis" << endl;
        myTxzy->move('x',5000,7000);
        Time::delay(0.2);
    }

    cout << "Home command" << endl;
    myTxzy->goHomePosition();
    Time::delay(0.2);

    for( int i = 0; i < 5; i++ )
    {
        cout << "----------------------" << endl;
        cout << "Moving command multiple axes" << endl;
        myTxzy->move(5000,5000,5000,5000,7000,7000,7000,7000);
        Time::delay(0.2);
    }


    cout << "Home command" << endl;
    myTxzy->goHomePosition();

    cout << "Closing port" << endl;
    myTxzy->closePort();

    cout << "OK" << endl;

    return 0;
}
