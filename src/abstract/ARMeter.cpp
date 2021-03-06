/*
	GUIDO Library
	Copyright (C) 2002  Holger Hoos, Juergen Kilian, Kai Renz

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

#include <iostream>
#include "secureio.h"

#include "ARMeter.h"
#include "TagParameterString.h"
#include "TagParameterFloat.h"
#include "TagParameterList.h"
#include "ListOfStrings.h"


ListOfTPLs ARMeter::ltpls(1);

ARMeter::ARMeter()
{
	mtype = NONE;
	autoBarlines = 1;
}

ARMeter::ARMeter(int p_numerator, int p_denominator)
{
	numerator = p_numerator;
	denominator = p_denominator;
	char buffer[20];
	snprintf(buffer, 20, "%d/%d",numerator,denominator);
	mMeterName = buffer;
	mtype = NUMERIC;
	autoBarlines = 1;
}


ARMeter::~ARMeter()
{
}


void ARMeter::print() const
{
}

std::ostream & ARMeter::operator<<(std::ostream & os) const
{
	// ATTENTION: evtl. problem, if we impl. a meter-sig that has no name
	if (mtype == NONE) return os;
	return os << "\\meter<\"" << mMeterName << "\"> ";
}

void ARMeter::setTagParameterList(TagParameterList& tpl)
{
	if (ltpls.GetCount() == 0)
	{
		// create a list of string ...
		ListOfStrings lstrs; // (1); std::vector test impl
		lstrs.AddTail("S,type,4/4,r;F,size,1.0,o;S,autoBarlines,on,o");
		CreateListOfTPLs(ltpls,lstrs);
	}

	TagParameterList * rtpl = NULL;
	int ret = MatchListOfTPLsWithTPL(ltpls,tpl,&rtpl);

	if (ret>=0 && rtpl)
	{
		// we found a match!
		if (ret == 0)
		{
			// then, we now the match for
			// the first ParameterList
			// w, h, ml, mt, mr, mb
			GuidoPos pos = rtpl->GetHeadPosition();

			TagParameterString * tps = TagParameterString::cast(rtpl->GetNext(pos));
			assert(tps);

			mMeterName = tps->getValue();

			TagParameterFloat * tpf = TagParameterFloat::cast(rtpl->GetNext(pos));
			assert(tpf);

			size = tpf->getValue();

			tps = TagParameterString::cast(rtpl->GetNext(pos));
			assert(tps);

			std::string off ("off");
			if (off == tps->getValue())
				autoBarlines = 0;
			else
				autoBarlines = 1;
			
			// now set  enumerator and
			// denominator 
			if (sscanf(mMeterName.c_str(),"%d/%d",&numerator,&denominator) != 2)
			{ // read error
				if (mMeterName == "C")
				{
					mtype = C;
					numerator = 4;
					denominator = 4;
				}
				else if (mMeterName == "C/")
				{
					mtype = C2;
					numerator = 2;
					denominator = 2;
				}
				else
				{
					numerator = 0;
					denominator = 1;
					mtype = NONE;
				}
			}
			else
				mtype = NUMERIC;
			
		}

		delete rtpl;
	}
	else
	{
		numerator = 0;
		denominator = 1;
		mtype = NONE;
	}

	tpl.RemoveAll();
}

bool ARMeter::IsStateTag() const
{
	return true;
}

TYPE_TIMEPOSITION ARMeter::getMeterTime() const
{
	return TYPE_TIMEPOSITION(numerator,denominator);
}
