#pragma once

#include "Subjects.h"
#include <string>
#include <vector>

class CData
{
public:
    //static const int m_nSubjects = 10;
    CData() :
        //m_nEducationType(0),
        m_nKnowProblem(0),
        m_nEducationalExperience(0),
        m_nPracticalExperience(0),
        m_nLaborMarketRequirements(0),
        m_nIntuition(0),
        m_arrSubject(Subjects::size),
        m_dCompetenceLevel(0)
    {
    }

    //std::string m_szFacultyName;
    //std::string m_szDepartmentName;
    //std::string m_szSpecialtyName;
   //int m_nEducationType;
    int m_nKnowProblem;
    int m_nEducationalExperience;
    int m_nPracticalExperience;
    int m_nLaborMarketRequirements;
    int m_nIntuition;
    std::vector<int> m_arrSubject;

    double m_dCompetenceLevel;
};


