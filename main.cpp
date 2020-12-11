#include <iostream>
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

    std::cout << "Point: Coil 1: (" << MainPointC10[0] << "," << MainPointC10[1] << ")" << std::endl;
    std::cout << "Point: Primary 1: (" << MainPointP11[0] << "," << MainPointP11[1] << ")" << std::endl;
    std::cout << "Point: Primary 2: (" << MainPointP12[0] << "," << MainPointP12[1] << ")" << std::endl;
    std::cout << "Point: Secondary 1: (" << MainPointS11[0] << "," << MainPointS11[1] << ")" << std::endl;
    std::cout << "Point: Secondary 2: (" << MainPointS12[0] << "," << MainPointS12[1] << ")" << std::endl;
    std::cout << "Point: Secondary 3: (" << MainPointS13[0] << "," << MainPointS13[1] << ")" << std::endl;
    std::cout << "Point: Secondary 4: (" << MainPointS14[0] << "," << MainPointS14[1] << ")" << std::endl;

    system("pause");
    return 0;
}