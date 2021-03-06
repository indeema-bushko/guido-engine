#ifndef GRPage_H
#define GRPage_H

/*
	GUIDO Library
	Copyright (C) 2002  Holger Hoos, Juergen Kilian, Kai Renz
	Copyright (C) 2003, 2004 Grame

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

#include <vector>

#include "GREvent.h"
#include "GUIDOEngine.h"			// for GuidoOnDrawDesc

class ARPageFormat;
class ARMusic;

class GRSystem;
class GRMusic;
class GRStaffManager;

extern GRSystem * gCurSystem;
extern NVRect gClipRect;

typedef std::vector<GRSystem *> SystemPointerList;

/** \brief Graphical representation of a score page.  
		Contains one or more instances of class GRSystem.
*/

class GRPage : public GREvent  
{
	public:
				GRPage( GRMusic * grmusic, GRStaffManager * grstafmgr,
						const TYPE_TIMEPOSITION  & inDate, GRPage * prevpage = 0 );
	virtual 	~GRPage();

	bool		addSystem( GRSystem * inSystem, float * ioUsedSystemDistance );
	void		systemFinished(GRSystem * inSystem);
	void		finishPage( bool islastpage = false ); // system distribution

	void		setSpringParameter(float npar);
	void		setPageFormat(ARPageFormat * inFormat);
	void 		adjustPageSize();

	//	virtual	SystemPointerList * getSystems();
	ARMusic *		getARMusic() const;

	// - Graphic
	virtual void	trace( VGDevice & hdc ) const;
	virtual void	OnDraw( VGDevice & hdc ) const;
	virtual void	OnDraw( VGDevice & hdc, const GuidoOnDrawDesc & inDrawInfos ) const;
	virtual void	GetMap( GuidoeElementSelector sel, MapCollector& f, MapInfos& infos ) const;
	
	virtual void	print() const;
	virtual void	GGSOutput() const;
	
	// - Page format: size and margins

			void	getMarginsCm( float * ml, float * mt, float * mr, float * mb );

			void	getPageFormat( GuidoPageFormat * outFormat ) const;

			float	getMarginLeft() const;
			float	getMarginTop() const;
			float	getMarginRight() const;
			float	getMarginBottom() const;
	
			float	getPageWidth() const;	// internal units
			float	getPageHeight() const;
			float	getInnerWidth() const;
			float	getInnerHeight() const;

			float	getPageWidthCm() const;
			float	getPageHeightCm() const;
			float	getInnerWidthCm() const;
			float	getInnerHeightCm() const;
	
			void	getScaling( float& vsizex, float& vsizey ) const;

	//	void convertToPixelSize( VGDevice & hdc, float zoom, float * pi1, float * pi2);
	//	void convertToVirtualSize( VGDevice & hdc, float zoom, float * pi1, float * pi2);
	//	float 	getZoom() const;
	//	virtual void setZoom(float p_zoom);

		TYPE_TIMEPOSITION mDebugPageDate;

		const SystemPointerList *  getSystems() const { return &mSystems; }

	protected:
				void	setScaling( VGDevice & hdc, float vsizex, float vsizey ) const;

		GRStaffManager * m_staffmgr;

		GRMusic * mCurMusic;

		float mLeftMargin;	// now in internal units
		float mTopMargin;
		float mRightMargin;
		float mBottomMargin;

		float mWidth;		// now in internal units
		float mHeight;

		float m_totalsystemheight;

		bool DPtoLPRect( VGDevice & hdc, float left, float top, 
							float right, float bottom, NVRect * outRect ) const;
		virtual void	updateBoundingBox();
		
		// old...
		void	setHorizontalSpacing();

		SystemPointerList  mSystems;
};

#endif
