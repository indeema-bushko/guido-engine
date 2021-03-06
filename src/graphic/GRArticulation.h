#ifndef GRArticulation_H
#define GRArticulation_H

/*
	GUIDO Library
	Copyright (C) 2002  Holger Hoos, Juergen Kilian, Kai Renz
	Copyright (C) 2004	Grame

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

#include "GRTagARNotationElement.h"
#include "NVPoint.h"


class GRStaff;
class ARMusicalTag;
class GREvent;

/*
class GRArticulationContext
{
	public:
	
		GREvent * event;
		GRStaff * staff;
			
};
*/
/** \brief Articulations: staccato, accent, marcato, 
			tenuto, fermata, breath-mark, harmonics
*/

class GRArticulation : public GRTagARNotationElement
{
  public:
	//  enum { STACCATO, ACCENT, MARCATO, TENUTO, FERMATA, BREATHMARK };
	
		enum {  kFlagStaccato = 1, kFlagStaccmo = 2, kFlagTenuto = 4,
				kFlagAccent = 8, kFlagMarcato = 16, 
				kFlagFermataUp = 32, kFlagFermataDown = 64, kFlagBreathMark = 128, 
				kFlagPizz = 256, kFlagHarmonic = 512 };


				GRArticulation( ARMusicalTag * inTag,
								float curLSPACE,	
								bool ownsar = false );

		virtual ~GRArticulation();

		virtual const NVPoint & getReferencePosition() const;

		// ignore positions 
		virtual void setPosition(const NVPoint & point);

		// this will be done by the event to which
		// the staccato belongs ....
		virtual void tellPosition(GObject * caller, const NVPoint & inPos);

		virtual void GGSOutput() const;
		virtual void OnDraw( VGDevice & hdc ) const;

		virtual void print() const;

		int	 getArticulationType() const { return mArticulationFlag; }

	protected:
	
		void	setupStaccato();
		void	setupStaccmo();
		void	setupLeftHPizz();
		void	setupSnapPizz();
		void	setupBuzzPizz();
		void	setupFingernailPizz();
		void	setupAccent();
		void	setupMarcato();
		void	setupTenuto();
		void	setupFermataUp();
		void	setupFermataDown();
		void	setupShortFermataUp();
		void	setupShortFermataDown();
		void	setupLongFermataUp();
		void	setupLongFermataDown();
		void	setupBreathMark();
		void	setupHarmonic();
		void	setArticulationSymbol( unsigned int inSymbolID );

		void	placeStaccato( GREvent * inParent, NVPoint & ioPos );
		void	placeStaccmo (GREvent * inParent, NVPoint & ioPos);
		void	placePizz(GREvent * inParent, NVPoint & ioPos);
		void	placeAccent( GREvent * inParent, NVPoint & ioPos );
		void	placeMarcato( GREvent * inParent, NVPoint & ioPos );
		void	placeTenuto( GREvent * inParent, NVPoint & ioPos );
		void	placeFermataUp( GREvent * inParent, NVPoint & ioPos );
		void	placeFermataDown( GREvent * inParent, NVPoint & ioPos );
		void	placeHarmonic (GREvent * inParent, NVPoint & ioPos);
		void	placeBreathMark( GREvent * inParent, NVPoint & ioPos );


	//	void	placeCloseToNote( GREvent * inParent, NVPoint & ioPos );
	//	void	placeOutsideStaff( GREvent * inParent, NVPoint & ioPos );

		GDirection	chooseDirection( GREvent * inParent ) const;

		void	placeAfterNote( GREvent * inParent, NVPoint & ioPos, 
													bool upward );

		void	setMarcatoDirection( bool upward );
		void	setStaccmoDirection( bool upward);

	//	bool	mOutsideStaffOnly;
		
	//	const type_info &tinfo; // could be replaced by the symbol constant ?
		int		mArticulationFlag;

		static NVPoint sRefposStacc;
		static NVPoint sRefposStaccmoUp;
		static NVPoint sRefposStaccmoDown;
		static NVPoint sRefposLeftHPizz;
		static NVPoint sRefposSnapPizz;
		static NVPoint sRefposBuzzPizz;
		static NVPoint sRefposFingernailPizz;
		static NVPoint sRefposAccent;
		static NVPoint sRefposMarcatoUp;
		static NVPoint sRefposMarcatoDown;
		static NVPoint sRefposTenuto;
		static NVPoint sRefposFermataUp;
		static NVPoint sRefposFermataDown;
		static NVPoint sRefposShortFermataUp;
		static NVPoint sRefposShortFermataDown;
		static NVPoint sRefposLongFermataUp;
		static NVPoint sRefposLongFermataDown;
		static NVPoint sRefposBreathMark;
		static NVPoint sRefposHarmonic;
};

#endif


