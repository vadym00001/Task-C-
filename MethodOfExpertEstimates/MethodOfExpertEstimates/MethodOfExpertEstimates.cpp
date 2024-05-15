#include "GetData.h"
#include "CalculateAlg.h"
#include <Windows.h>
#include <iostream>

void Output(const std::vector<CCalcData>& arrResults, const std::vector<CData>& arrData)
{
    std::cout << "\n___________________________________________________________________________";
    std::cout << "\nЗа результатами експертних оцінок визначено наступний рейтинг альтернатив:\n";
    std::cout << "___________________________________________________________________________\n\n";


    for (std::vector<CCalcData>::const_iterator iter = arrResults.begin();
        iter < arrResults.end(); iter++)
    {
        switch (iter->m_nIndex)
        {
        case Subjects::english:
            std::cout << "Вивчення іноземної мови " << "(рейтинговий бал: " << iter->m_dImportenceCriterion << ").\n\n";
            break;

        case Subjects::languageCC:
            std::cout << "Програмування мовою C++ " << "(рейтинговий бал: " << iter->m_dImportenceCriterion << ").\n\n";
            break;

        case Subjects::languageJava:
            std::cout << "Програмування мовою Java " << "(рейтинговий бал: " << iter->m_dImportenceCriterion << ").\n\n";
            break;

        case Subjects::languageC:
            std::cout << "Програмування мовою C# " << "(рейтинговий бал: " << iter->m_dImportenceCriterion << ").\n\n";
            break;

        case Subjects::languagePy:
            std::cout << "Програмування мовою Python " << "(рейтинговий бал: " << iter->m_dImportenceCriterion << ").\n\n";
            break;

        case Subjects::web:
            std::cout << "Веб-програмування " << "(рейтинговий бал: " << iter->m_dImportenceCriterion << ").\n\n";
            break;

        case Subjects::qa:
            std::cout << "Тестування програмного забезпечення " << "(рейтинговий бал: " << iter->m_dImportenceCriterion << ").\n\n";
            break;

        case Subjects::cybersecurity:
            std::cout << "Кібербезпека " << "(рейтинговий бал: " << iter->m_dImportenceCriterion << ").\n\n";
            break;

        case Subjects::artificialIntelligence:
            std::cout << "Штучний інтелект та нейронні мережі " << "(рейтинговий бал: " << iter->m_dImportenceCriterion << ").\n\n";
            break;

        case Subjects::progForMob:
            std::cout << "Програмування для мобільних платформ " << "(рейтинговий бал: " << iter->m_dImportenceCriterion << ").\n\n";
            break;

        default:
            std::cout << "Error !!!\n";
            break;
        }
    }

    std::cout << "___________________________________________________________________________\n";

    std::cout << "Експерти визначили ступінь обізнаності з проблемою, оцінюючи запропановані\nаспекти власного досвіду за"
                 " трьохбальною шкалою, де:\n1 - високий; \n2 - низький; \n3 - середній.\n";

    for (unsigned int i = 0; i < arrData.size(); i++)
    {
        const CData& data = arrData[i];

        std::cout << "___________________________________________________________________________\n";
        std::cout << i + 1 << "-ий експерт:\n";
        std::cout << "___________________________________________________________________________\n";
        std::cout << "\nНавчальний досвід - " << data.m_nEducationalExperience;
        std::cout << "\n\nДосвід практичної роботи - " << data.m_nPracticalExperience;
        std::cout << "\n\nВимоги ринку праці - " << data.m_nLaborMarketRequirements;
        std::cout << "\n\nІнтуїція - " << data.m_nIntuition;
        std::cout << "\n\n";
    }

}

int main()
{
    SetConsoleOutputCP(1251);

    std::vector<CData> arrData;
    CGetData getData;
    CCalculateAlg calculateAlg(Subjects::size);

    getData.GetData(arrData);
    calculateAlg.Calculate(arrData);
    Output(calculateAlg.GetResults(), arrData);
}


