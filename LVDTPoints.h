#include <iostream>
#pragma once

class Points
{
    private:
        float CoreLenght,         // Core lenght [mm]
            CoreRadius,           // Core radius [mm]
            PrimaryLenght,        // Primary Coil lengh [mm]
            PrimaryExtRadius,     // Primary Coil external radius [mm]
            PrimaryIntRadius,     // Primary Coil internal radius [mm]
            SecondaryLenght,      // Secondary Coil lengh [mm]
            SecondaryExtRadius,   // Secondary Coil external radius [mm]
            SecondaryIntRadius,   // Secondary Coil internal radius [mm]
            SecondarySepparation; // Secondary Coil sepparation [mm]
        
    public:
        // Default Constructor
        Points();
        // Constructor
        Points(
            float _CoreLenght, 
            float _CoreRadius, 
            float _PrimaryLenght, 
            float _PrimaryExtRadius,
            float _PrimaryIntRadius,
            float _SecondaryLenght,
            float _SecondaryExtRadius,
            float _SecondaryIntRadius,
            float _SecondarySepparation
            );

        // Points calculation
        void PointC10(float (&P)[2]);
        void PointP11(float (&P)[2]);
        void PointP12(float (&P)[2]);
        void PointS11(float (&P)[2]);
        void PointS12(float (&P)[2]);
        void PointS13(float (&P)[2]);
        void PointS14(float (&P)[2]);
        void CoreMat(float (&P)[2]);
        void PrimaryMat(float (&P)[2]);
        void SecondaryMat(float (&P)[2]);
};