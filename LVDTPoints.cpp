#include <iostream>
#include "LVDTPoints.h"

#define OUT

// Default Construtor deff
Points::Points(){};

// Construtor deff
Points::Points(
            float _CoreLenght, 
            float _CoreRadius, 
            float _PrimaryLenght, 
            float _PrimaryExtRadius,
            float _PrimaryIntRadius,
            float _SecondaryLenght,
            float _SecondaryExtRadius,
            float _SecondaryIntRadius,
            float _SecondarySepparation
            )
{
    CoreLenght = _CoreLenght; 
    CoreRadius = _CoreRadius; 
    PrimaryLenght = _PrimaryLenght; 
    PrimaryExtRadius = _PrimaryExtRadius;
    PrimaryIntRadius = _PrimaryIntRadius;
    SecondaryLenght = _SecondaryLenght;
    SecondaryExtRadius = _SecondaryExtRadius;
    SecondaryIntRadius = _SecondaryIntRadius;
    SecondarySepparation = _SecondarySepparation;           
};

// Points deff
void Points::PointC10(float (&P)[2])
{
    P[1] = CoreLenght / 2.f;
    P[0] = CoreRadius;
}


void Points::PointP11(float (&P)[2])
{
    P[1] = PrimaryLenght / 2.f;
    P[0] = PrimaryIntRadius;
}


void Points::PointP12(float (&P)[2])
{
    P[1] = PrimaryLenght / 2.f;
    P[0] = PrimaryExtRadius;
}


void Points::PointS11(float (&P)[2])
{
    P[1] = SecondaryLenght / 2.f;
    P[0] = SecondaryIntRadius;
}


void Points::PointS12(float (&P)[2])
{
    P[1] = SecondaryLenght / 2.f;
    P[0] = SecondaryExtRadius;
}


void Points::PointS13(float (&P)[2])
{
    P[1] = SecondarySepparation / 2.f;
    P[0] = SecondaryExtRadius;
}


void Points::PointS14(float (&P)[2])
{
    P[1] = SecondarySepparation / 2.f;
    P[0] = SecondaryIntRadius;
}