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
    P[0] = CoreRadius;
    P[1] = CoreLenght / 2.f;
}


void Points::PointP11(float (&P)[2])
{
    P[0] = PrimaryIntRadius;
    P[1] = PrimaryLenght / 2.f;
}


void Points::PointP12(float (&P)[2])
{
    P[0] = PrimaryExtRadius;
    P[1] = PrimaryLenght / 2.f;
}


void Points::PointS11(float (&P)[2])
{
    P[0] = SecondaryIntRadius;
    P[1] = SecondaryLenght / 2.f;
}


void Points::PointS12(float (&P)[2])
{
    P[0] = SecondaryExtRadius;
    P[1] = SecondaryLenght / 2.f;
}


void Points::PointS13(float (&P)[2])
{
    P[0] = SecondaryExtRadius;
    P[1] = SecondarySepparation / 2.f;
}


void Points::PointS14(float (&P)[2])
{
    P[0] = SecondaryIntRadius;
    P[1] = SecondarySepparation / 2.f;
}

void Points::CoreMat(float (&P)[2])
{
    P[0] = 0.f;
    P[1] = 0.f;
}

void Points::PrimaryMat(float (&P)[2])
{
    P[0] = PrimaryIntRadius + (PrimaryExtRadius - PrimaryIntRadius)/2.f;
    P[1] = 0.f;
}

void Points::SecondaryMat(float (&P)[2])
{
    P[0] = SecondaryIntRadius + (SecondaryExtRadius - SecondaryIntRadius)/2.f;
    P[1] = SecondarySepparation  + (SecondaryLenght - SecondarySepparation)/4.f;
}
