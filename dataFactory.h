//
// Created by 胡小赖 on 2018/6/30.
//

#ifndef OOPPROJECT_DATAFACTORY_H
#define OOPPROJECT_DATAFACTORY_H

#include <istream>
#include "baseData.h"

#include "Rate.h"
#include "Director.h"
#include "Release_Date.h"
#include "Screenwriter.h"
#include "Actor.h"
#include "Genre.h"
#include "Runtime.h"
#include "Review.h"
#include "BoxOffice.h"

class dataFactory {
public:
    static baseData* createData(std::string _type,std::string _value);
};


#endif //OOPPROJECT_DATAFACTORY_H
