#ifndef GRSpacingMatrix_H
#define GRSpacingMatrix_H

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

class GRSpring;

template <class T> class KF_IVector;
template <class T> class KF_List;
template <class T> class KF_IPointerList;

typedef KF_List<int> intlist;
typedef KF_IPointerList<intlist> listofpointerstointlists;

typedef KF_IVector<GRSpring> ISpringVector;

/** \brief not yet documented
*/
class GRSpacingMatrix
{
	public:
					GRSpacingMatrix();
		virtual		~GRSpacingMatrix();

		int			getMSCMatrixRealSize();
		int			getMSCMatrixMemSize();
		double *	getMSCMatrix();

		double		getMSCMatrix(int i,int j) const;
		void		setMSCMatrix(int i,int j, double value);

		double *	resizeMSCMatrix( int newrealsize );

		void		AddNeighbourList(KF_List<int> * nl);

		void		CheckNeighbours(ISpringVector *sprvect);
 
	protected:

		int			mMatrixMemSize;
		int			mMatrixRealSize;
		double *	mMatrix;

		listofpointerstointlists * mNeighbours;
		listofpointerstointlists * mNeighboursRight;

		int mLastLeft;
		int mLastRight;

};

#endif
