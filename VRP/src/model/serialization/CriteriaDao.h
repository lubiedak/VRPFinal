/*
 * CriteriaDao.h
 *
 *  Created on: 15 Jan 2016
 *      Author: lubiedak
 */

#ifndef MODEL_SERIALIZATION_CRITERIADAO_H_
#define MODEL_SERIALIZATION_CRITERIADAO_H_

#include "Serialized.h"
#include "../Criteria.h"

class CriteriaDao : public Serialized {
public:
	CriteriaDao(Criteria c);
	virtual ~CriteriaDao();


	virtual std::string serialize();
	virtual bool deserialize(std::string);

private:
	Criteria c;

};

#endif /* MODEL_SERIALIZATION_CRITERIADAO_H_ */
