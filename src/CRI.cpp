//
// Created by Bar Oren on 14/06/2022.
//

#include <CRI.h>

#include "CRI.h"

void CRIclass::calcCRI(int c, int r, int i) {
    int sum = c + r + i;
    if (c == 0 && r == 0 && i == 0) {
        sum = 1;
        for (int j = 0; j < m_CRI.size(); ++j) {
            m_CRI[j] = 33;
        }
        return;
    }
    m_CRI[int(CRI::C)] = static_cast< float >(c) / static_cast< float >(sum) * CAL;//CAL==100
    m_CRI[int(CRI::R)] = static_cast< float >(r) / static_cast< float >(sum) * CAL;//CAL==100
    m_CRI[int(CRI::I)] = static_cast< float >(i) / static_cast< float >(sum) * CAL;//CAL==100
    for (int j = 0; j < m_CRI.size(); ++j) {
      //  std::cout << m_CRI[j] << std::endl;
    }


}

void CRIclass::update() {
    for (int i = 0; i < m_CRI.size(); ++i) {
        if (m_CRI[i] < 30)
            std::cout << m_need[i];
    }

}
