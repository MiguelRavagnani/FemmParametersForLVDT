#include <iostream>
#include <fstream>

#include "LVDTPoints.h"

int main()
{
    // Variables declaration
    float MainPointC10[2],
        MainPointP11[2],
        MainPointP12[2],
        MainPointS11[2],
        MainPointS12[2],
        MainPointS13[2],
        MainPointS14[2];

    // Parametersariables declaration
    float MainCoreLenght,    
        MainCoreRadius,      
        MainPrimaryLenght,   
        MainPrimaryExtRadius,
        MainPrimaryIntRadius,
        MainSecondaryLenght,
        MainSecondaryExtRadius,
        MainSecondaryIntRadius,
        MainSecondarySepparation;

    // File Name
    char filename[11] = "points.lua";

    std::cout << "Iinsert, in the respective order, the LDVT parameters separeted by whitespaces:\n"
            << "Core lenght [mm]\n"
            << "Core radius [mm]\n"
            << "Primary Coil lengh [mm]\n"
            << "Primary Coil external radius [mm]\n"
            << "Primary Coil internal radius [mm]\n"
            << "Secondary Coil lengh [mm]\n"
            << "Secondary Coil external radius [mm]\n"
            << "Secondary Coil internal radius [mm]\n"
            << "Secondary Coil sepparation [mm]\n" << std::endl;

    std::cin >> MainCoreLenght    
            >> MainCoreRadius      
            >> MainPrimaryLenght   
            >> MainPrimaryExtRadius
            >> MainPrimaryIntRadius
            >> MainSecondaryLenght
            >> MainSecondaryExtRadius
            >> MainSecondaryIntRadius
            >> MainSecondarySepparation;

    // Points object call
    Points FirstQuad(
                MainCoreLenght, 
                MainCoreRadius, 
                MainPrimaryLenght, 
                MainPrimaryExtRadius,
                MainPrimaryIntRadius,
                MainSecondaryLenght,
                MainSecondaryExtRadius,
                MainSecondaryIntRadius,
                MainSecondarySepparation
            );

    // Calculating Points
    FirstQuad.PointC10(MainPointC10);
    FirstQuad.PointP11(MainPointP11);
    FirstQuad.PointP12(MainPointP12);
    FirstQuad.PointS11(MainPointS11);
    FirstQuad.PointS12(MainPointS12);
    FirstQuad.PointS13(MainPointS13);
    FirstQuad.PointS14(MainPointS14);

    // Remove old file and create new one
    if (remove(filename) != 0)
    {
        perror("\nFile could not be deleted!\n");
    }
    else
    {
        std::cout << "\nFile deleted\n" << std::endl;
    }  
    std::ofstream outfile(filename);

    if(!outfile.is_open())
    {
        std::cout << "\nUnable to open file!\n" << std::endl;
    }
    else
    {
        // Starts the Lua Scripting
        outfile << "clearconsole()" << std::endl; 
        outfile << "newdocument(0)" << std::endl;
        outfile << "messagebox(\"Debug\")" << std::endl;
        outfile << "pause()" << std::endl;

        // Core points
        //     - Point PC10 (x,y): First Quard core point
        //     - Point PC10 (-x,y): Second Quard core point
        //     - Point PC10 (-x,-y): Third Quard core point
        //     - Point PC10 (x,-y): Fourth Quard core point
        outfile << "mi_addnode(" << MainPointC10[0] << "," << MainPointC10[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << -1.f * MainPointC10[0] << "," << MainPointC10[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << -1.f * MainPointC10[0] << "," << -1.f * MainPointC10[1] <<  ")" << std::endl;     
        outfile << "mi_addnode(" << MainPointC10[0] << "," << -1.f * MainPointC10[1] <<  ")" << std::endl;

        // Primary points
        //     - Point Pp11 (x,y): First Quard core point
        //       Point Pp12 (x,y): First Quard core point
        //     - Point Pp11 (-x,y): Second Quard core point
        //       Point Pp12 (-x,y): Second Quard core point
        //     - Point Pp11 (-x,-y): Third Quard core point
        //       Point Pp12 (-x,-y): Third Quard core point
        //     - Point Pp11 (x,-y): Fourth Quard core point
        //       Point Pp12 (x,-y): Fourth Quard core point
        outfile << "mi_addnode(" << MainPointP11[0] << "," << MainPointP11[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << MainPointP12[0] << "," << MainPointP12[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << -1.f * MainPointP11[0] << "," << MainPointP11[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << -1.f * MainPointP12[0] << "," << MainPointP12[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << -1.f * MainPointP11[0] << "," << -1.f * MainPointP11[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << -1.f * MainPointP12[0] << "," << -1.f * MainPointP12[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << MainPointP11[0] << "," << -1.f * MainPointP11[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << MainPointP12[0] << "," << -1.f * MainPointP12[1] <<  ")" << std::endl;

        // Secondary points
        //     - Point Ps11 (x,y): First Quard core point
        //       Point Ps12 (x,y): First Quard core point
        //       Point Ps13 (x,y): First Quard core point
        //       Point Ps14 (x,y): First Quard core point
        //     - Point Ps11 (-x,y): Second Quard core point
        //       Point Ps12 (-x,y): Second Quard core point
        //       Point Ps13 (-x,y): Second Quard core point
        //       Point Ps14 (-x,y): Second Quard core point
        //     - Point Ps11 (-x,-y): Third Quard core point
        //       Point Ps12 (-x,-y): Third Quard core point
        //       Point Ps13 (-x,-y): Third Quard core point0
        //       Point Ps14 (-x,-y): Third Quard core point
        //     - Point Ps11 (x,-y): Fourth Quard core point
        //       Point Ps12 (x,-y): Fourth Quard core point
        //       Point Ps13 (x,-y): Fourth Quard core point
        //       Point Ps14 (x,-y): Fourth Quard core point
        outfile << "mi_addnode(" << MainPointS11[0] << "," << MainPointS11[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << MainPointS12[0] << "," << MainPointS12[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << MainPointS13[0] << "," << MainPointS13[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << MainPointS14[0] << "," << MainPointS14[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << -1.f * MainPointS11[0] << "," << MainPointS11[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << -1.f * MainPointS12[0] << "," << MainPointS12[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << -1.f * MainPointS13[0] << "," << MainPointS13[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << -1.f * MainPointS14[0] << "," << MainPointS14[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << -1.f * MainPointS11[0] << "," << -1.f * MainPointS11[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << -1.f * MainPointS12[0] << "," << -1.f * MainPointS12[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << -1.f * MainPointS13[0] << "," << -1.f * MainPointS13[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << -1.f * MainPointS14[0] << "," << -1.f * MainPointS14[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << MainPointS11[0] << "," << -1.f * MainPointS11[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << MainPointS12[0] << "," << -1.f * MainPointS12[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << MainPointS13[0] << "," << -1.f * MainPointS13[1] <<  ")" << std::endl;
        outfile << "mi_addnode(" << MainPointS14[0] << "," << -1.f * MainPointS14[1] <<  ")" << std::endl;

        // Core Segments
        outfile << "mi_addsegment(" 
                << MainPointC10[0] << "," 
                << MainPointC10[1] << "," 
                <<  -1.f * MainPointC10[0] << "," 
                << MainPointC10[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << MainPointC10[0] << "," 
                << MainPointC10[1] << "," 
                << MainPointC10[0] << "," 
                << -1.f * MainPointC10[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << MainPointC10[0] << "," 
                << -1.f * MainPointC10[1] << "," 
                << -1.f * MainPointC10[0] << "," 
                << -1.f * MainPointC10[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << -1.f * MainPointC10[0] << "," 
                << -1.f * MainPointC10[1] << "," 
                << -1.f * MainPointC10[0] << "," 
                << MainPointC10[1] << ")" << std::endl;

        // Primary Segments
        outfile << "mi_addsegment(" 
                << MainPointP11[0] << "," 
                << MainPointP11[1] << "," 
                << MainPointP12[0] << "," 
                << MainPointP12[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << MainPointP12[0] << "," 
                << MainPointP12[1] << "," 
                << MainPointP12[0] << "," 
                << -1.f * MainPointP12[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << MainPointP12[0] << "," 
                << -1.f * MainPointP12[1] << "," 
                << MainPointP11[0] << "," 
                << -1.f * MainPointP11[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << MainPointP11[0] << "," 
                << -1.f * MainPointP11[1] << "," 
                << MainPointP11[0] << "," 
                << MainPointP11[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << -1.f * MainPointP11[0] << "," 
                << MainPointP11[1] << "," 
                << -1.f * MainPointP12[0] << "," 
                << MainPointP12[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << -1.f * MainPointP12[0] << "," 
                << MainPointP12[1] << "," 
                << -1.f * MainPointP12[0] << "," 
                << -1.f * MainPointP12[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << -1.f * MainPointP12[0] << "," 
                << -1.f * MainPointP12[1] << "," 
                << -1.f * MainPointP11[0] << "," 
                << -1.f * MainPointP11[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << -1.f * MainPointP11[0] << "," 
                << -1.f * MainPointP11[1] << "," 
                << -1.f * MainPointP11[0] << "," 
                << MainPointP11[1] << ")" << std::endl;

        // Primary Segments
        outfile << "mi_addsegment(" 
                << MainPointS11[0] << "," 
                << MainPointS11[1] << "," 
                << MainPointS12[0] << "," 
                << MainPointS12[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << MainPointS12[0] << "," 
                << MainPointS12[1] << "," 
                << MainPointS13[0] << "," 
                << MainPointS13[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << MainPointS13[0] << "," 
                << MainPointS13[1] << "," 
                << MainPointS14[0] << "," 
                << MainPointS14[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << MainPointS14[0] << "," 
                << MainPointS14[1] << "," 
                << MainPointS11[0] << "," 
                << MainPointS11[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << MainPointS11[0] << "," 
                << -1.f * MainPointS11[1] << "," 
                << MainPointS12[0] << "," 
                << -1.f * MainPointS12[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << MainPointS12[0] << "," 
                << -1.f * MainPointS12[1] << "," 
                << MainPointS13[0] << "," 
                << -1.f * MainPointS13[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << MainPointS13[0] << "," 
                << -1.f * MainPointS13[1] << "," 
                << MainPointS14[0] << "," 
                << -1.f * MainPointS14[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << MainPointS14[0] << "," 
                << -1.f * MainPointS14[1] << "," 
                << MainPointS11[0] << "," 
                << -1.f * MainPointS11[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << -1.f * MainPointS11[0] << "," 
                << MainPointS11[1] << "," 
                << -1.f * MainPointS12[0] << "," 
                << MainPointS12[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << -1.f * MainPointS12[0] << "," 
                << MainPointS12[1] << "," 
                << -1.f * MainPointS13[0] << "," 
                << MainPointS13[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << -1.f * MainPointS13[0] << "," 
                << MainPointS13[1] << "," 
                << -1.f * MainPointS14[0] << "," 
                << MainPointS14[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << -1.f * MainPointS14[0] << "," 
                << MainPointS14[1] << "," 
                << -1.f * MainPointS11[0] << "," 
                << MainPointS11[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << -1.f * MainPointS11[0] << "," 
                << -1.f * MainPointS11[1] << "," 
                << -1.f * MainPointS12[0] << "," 
                << -1.f * MainPointS12[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << -1.f * MainPointS12[0] << "," 
                << -1.f * MainPointS12[1] << "," 
                << -1.f * MainPointS13[0] << "," 
                << -1.f * MainPointS13[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << -1.f * MainPointS13[0] << "," 
                << -1.f * MainPointS13[1] << "," 
                << -1.f * MainPointS14[0] << "," 
                << -1.f * MainPointS14[1] << ")" << std::endl;

        outfile << "mi_addsegment(" 
                << -1.f * MainPointS14[0] << "," 
                << -1.f * MainPointS14[1] << "," 
                << -1.f * MainPointS11[0] << "," 
                << -1.f * MainPointS11[1] << ")" << std::endl;
        outfile.close();

        std::cout << "\nOutput Successful!\n" << std::endl;
    }

    system("pause");
    return 0;
}