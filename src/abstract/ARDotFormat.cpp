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
#include "ARDotFormat.h"
#include "TagParameterString.h"
#include "TagParameterInt.h"
#include "TagParameterList.h"
#include "ListOfStrings.h"

ListOfTPLs ARDotFormat::ltpls(1);

const ARDotFormat defaultARDotFormat(NULL,NULL);


ARDotFormat::ARDotFormat(ARDotFormat *p_savedf,ARDotFormat *copydf)
: ARMTParameter(-1,copydf)
{
	// this probably should be changed to RANGEDC
	// but then we have to take care of saving state-information ....
	rangesetting = ARMusicalTag::RANGEDC;
	savedf = p_savedf;
	mDD = NULL;

	if (copydf && copydf->getDD())
	{
		mDD = TagParameterFloat::cast(copydf->getDD()->getCopy());
	}
	else if (!copydf)
	{
		TagParameterList tpl;
		setTagParameterList(tpl);
	}
}


ARDotFormat::~ARDotFormat()
{
	delete mDD;
}

void ARDotFormat::setTagParameterList(TagParameterList &tpl)
{
	if (ltpls.GetCount() == 0)
	{
		// create a list of string ...
		ListOfStrings lstrs; // (1); std::vector test impl
		lstrs.AddTail(("U,dx,1.8hs,o;U,dy,,o;F,size,1.0,o;U,dd,1hs,o"));
		CreateListOfTPLs(ltpls,lstrs);
	}

	TagParameterList * rtpl = NULL;
	int ret = MatchListOfTPLsWithTPL(ltpls,tpl,&rtpl);

	if (ret >=0 && rtpl)
	{
		// we found a match!
		if (ret == 0)
		{
			// this is different from the rest because we have a 
			// "generic" entry that governs DotFormats ...
			delete mDx;
			mDx = TagParameterFloat::cast(rtpl->RemoveHead()); 
			assert(mDx);

			delete mDy;
			mDy = TagParameterFloat::cast(rtpl->RemoveHead()); 
			assert(mDy);

			delete size;
			size = TagParameterFloat::cast(rtpl->RemoveHead()); 
			assert(size);

			delete mDD;
			mDD = TagParameterFloat::cast(rtpl->RemoveHead()); 
			assert(mDD);
		}
		delete rtpl;
	}
	else
	{
		// failure
	}
	tpl.RemoveAll();
}

void ARDotFormat::PrintName(std::ostream & os) const
{
	os << "\\dotFormat";
}

void ARDotFormat::PrintParameters(std::ostream & os) const
{
	int previous = 0;
	int isset = 0;
	if ((mDx && mDx->TagIsSet()) || (mDy && mDy->TagIsSet()) || (size && size->TagIsSet()) || (mDD && mDD->TagIsSet()))
	{
		isset = 1;
	}

	if (isset)
		os << "<";

	if (mDx && mDx->TagIsSet())
	{
		os << "dx=" << mDx->getUnitValue() << mDx->getUnit();
		previous = 1;
	}
	if (mDy && mDy->TagIsSet())
	{
		if (previous)
			os << ",";
		os << "dy=" << mDy->getUnitValue() << mDy->getUnit();
		previous = 1;
	}
	if (size && size->TagIsSet())
	{
		if (previous)
			os << ",";
		os << "dy=" << size->getValue(); // Should not be "size=" instead of "dy=" ?
		previous = 1;
	}
	if (mDD && mDD->TagIsSet())
	{
		if (previous)
			os << ",";
		os << "mDD=" << mDD->getUnitValue() << mDD->getUnit();
	}

	if (isset)
		os << ">";
}

