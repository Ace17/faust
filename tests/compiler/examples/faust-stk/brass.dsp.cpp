//-----------------------------------------------------
// name: "Brass"
// author: "Romain Michon (rmichon@ccrma.stanford.edu)"
// copyright: "Romain Michon"
// version: "1.0"
//
// Code generated with Faust 0.9.70 (http://faust.grame.fr)
//-----------------------------------------------------
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  

typedef long double quad;
/* link with  */
#include <math.h>
#ifndef FAUSTPOWER
#define FAUSTPOWER
#include <cmath>
template <int N> inline float faustpower(float x)          { return powf(x,N); } 
template <int N> inline double faustpower(double x)        { return pow(x,N); }
template <int N> inline int faustpower(int x)              { return faustpower<N/2>(x) * faustpower<N-N/2>(x); } 
template <>   inline int faustpower<0>(int x)            { return 1; }
template <>   inline int faustpower<1>(int x)            { return x; }
#endif

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
  private:
	class SIG0 {
	  private:
		int 	fSamplingFreq;
		int 	iRec13[2];
	  public:
		int getNumInputs() 	{ return 0; }
		int getNumOutputs() 	{ return 1; }
		void init(int samplingFreq) {
			fSamplingFreq = samplingFreq;
			for (int i=0; i<2; i++) iRec13[i] = 0;
		}
		void fill (int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec13[0] = (1 + iRec13[1]);
				output[i] = sinf((9.587379924285257e-05f * float((iRec13[0] - 1))));
				// post processing
				iRec13[1] = iRec13[0];
			}
		}
	};


	FAUSTFLOAT 	fslider0;
	float 	fRec0[2];
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT 	fentry0;
	int 	iConst0;
	float 	fConst1;
	int 	iConst2;
	FAUSTFLOAT 	fslider2;
	float 	fVec0[2];
	FAUSTFLOAT 	fslider3;
	float 	fRec4[2];
	FAUSTFLOAT 	fentry1;
	FAUSTFLOAT 	fbutton0;
	int 	iRec5[2];
	FAUSTFLOAT 	fslider4;
	FAUSTFLOAT 	fslider5;
	float 	fRec6[2];
	float 	fRec12[2];
	float 	fRec11[2];
	float 	fRec10[2];
	float 	fRec9[2];
	float 	fRec8[2];
	float 	fRec7[2];
	static float 	ftbl0[65536];
	FAUSTFLOAT 	fslider6;
	float 	fRec15[2];
	float 	fConst3;
	float 	fConst4;
	float 	fRec14[2];
	float 	fRec21[2];
	float 	fRec20[2];
	float 	fRec19[2];
	float 	fRec18[2];
	float 	fRec17[2];
	float 	fRec16[2];
	FAUSTFLOAT 	fslider7;
	float 	fRec22[2];
	int 	iRec23[2];
	int 	iRec24[2];
	FAUSTFLOAT 	fslider8;
	FAUSTFLOAT 	fslider9;
	FAUSTFLOAT 	fslider10;
	float 	fRec25[2];
	FAUSTFLOAT 	fslider11;
	int 	iRec26[2];
	FAUSTFLOAT 	fslider12;
	FAUSTFLOAT 	fslider13;
	float 	fRec27[2];
	FAUSTFLOAT 	fslider14;
	float 	fRec3[3];
	float 	fVec1[2];
	float 	fRec2[2];
	int 	IOTA;
	float 	fRec1[8192];
	FAUSTFLOAT 	fslider15;
	FAUSTFLOAT 	fentry2;
	float 	fConst5;
	float 	fConst6;
	float 	fConst7;
	float 	fConst8;
	float 	fRec39[2];
	FAUSTFLOAT 	fslider16;
	float 	fConst9;
	float 	fConst10;
	float 	fConst11;
	float 	fConst12;
	float 	fConst13;
	float 	fRec38[2];
	float 	fVec2[8192];
	float 	fConst14;
	int 	iConst15;
	float 	fVec3[4096];
	int 	iConst16;
	float 	fVec4[2048];
	int 	iConst17;
	float 	fRec36[2];
	float 	fRec43[2];
	float 	fConst18;
	float 	fConst19;
	float 	fConst20;
	float 	fConst21;
	float 	fRec42[2];
	float 	fVec5[8192];
	float 	fConst22;
	int 	iConst23;
	float 	fVec6[1024];
	int 	iConst24;
	float 	fRec40[2];
	float 	fRec47[2];
	float 	fConst25;
	float 	fConst26;
	float 	fConst27;
	float 	fConst28;
	float 	fRec46[2];
	float 	fVec7[8192];
	float 	fConst29;
	int 	iConst30;
	float 	fVec8[2048];
	int 	iConst31;
	float 	fRec44[2];
	float 	fRec51[2];
	float 	fConst32;
	float 	fConst33;
	float 	fConst34;
	float 	fConst35;
	float 	fRec50[2];
	float 	fVec9[8192];
	float 	fConst36;
	int 	iConst37;
	float 	fVec10[1024];
	int 	iConst38;
	float 	fRec48[2];
	float 	fRec55[2];
	float 	fConst39;
	float 	fConst40;
	float 	fConst41;
	float 	fConst42;
	float 	fRec54[2];
	float 	fVec11[16384];
	float 	fConst43;
	int 	iConst44;
	float 	fVec12[4096];
	FAUSTFLOAT 	fslider17;
	float 	fConst45;
	float 	fVec13[4096];
	float 	fVec14[2048];
	int 	iConst46;
	float 	fRec52[2];
	float 	fRec59[2];
	float 	fConst47;
	float 	fConst48;
	float 	fConst49;
	float 	fConst50;
	float 	fRec58[2];
	float 	fVec15[8192];
	float 	fConst51;
	int 	iConst52;
	float 	fVec16[2048];
	int 	iConst53;
	float 	fRec56[2];
	float 	fRec63[2];
	float 	fConst54;
	float 	fConst55;
	float 	fConst56;
	float 	fConst57;
	float 	fRec62[2];
	float 	fVec17[16384];
	float 	fConst58;
	int 	iConst59;
	float 	fVec18[2048];
	int 	iConst60;
	float 	fRec60[2];
	float 	fRec67[2];
	float 	fConst61;
	float 	fConst62;
	float 	fConst63;
	float 	fConst64;
	float 	fRec66[2];
	float 	fVec19[16384];
	float 	fConst65;
	int 	iConst66;
	float 	fVec20[1024];
	int 	iConst67;
	float 	fRec64[2];
	float 	fRec28[3];
	float 	fRec29[3];
	float 	fRec30[3];
	float 	fRec31[3];
	float 	fRec32[3];
	float 	fRec33[3];
	float 	fRec34[3];
	float 	fRec35[3];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "Brass");
		m->declare("description", "WaveGuide Brass instrument from STK");
		m->declare("author", "Romain Michon (rmichon@ccrma.stanford.edu)");
		m->declare("copyright", "Romain Michon");
		m->declare("version", "1.0");
		m->declare("licence", "STK-4.3");
		m->declare("reference", "https://ccrma.stanford.edu/~jos/pasp/Brasses.html");
		m->declare("music.lib/name", "Music Library");
		m->declare("music.lib/author", "GRAME");
		m->declare("music.lib/copyright", "GRAME");
		m->declare("music.lib/version", "1.0");
		m->declare("music.lib/license", "LGPL with exception");
		m->declare("math.lib/name", "Math Library");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/version", "1.0");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("instrument.lib/name", "Faust-STK Tools Library");
		m->declare("instrument.lib/author", "Romain Michon (rmichon@ccrma.stanford.edu)");
		m->declare("instrument.lib/copyright", "Romain Michon");
		m->declare("instrument.lib/version", "1.0");
		m->declare("instrument.lib/licence", "STK-4.3");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("filter.lib/copyright", "Julius O. Smith III");
		m->declare("filter.lib/version", "1.29");
		m->declare("filter.lib/license", "STK-4.3");
		m->declare("filter.lib/reference", "https://ccrma.stanford.edu/~jos/filters/");
		m->declare("effect.lib/name", "Faust Audio Effect Library");
		m->declare("effect.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("effect.lib/copyright", "Julius O. Smith III");
		m->declare("effect.lib/version", "1.33");
		m->declare("effect.lib/license", "STK-4.3");
		m->declare("effect.lib/exciter_name", "Harmonic Exciter");
		m->declare("effect.lib/exciter_author", "Priyanka Shekar (pshekar@ccrma.stanford.edu)");
		m->declare("effect.lib/exciter_copyright", "Copyright (c) 2013 Priyanka Shekar");
		m->declare("effect.lib/exciter_version", "1.0");
		m->declare("effect.lib/exciter_license", "MIT License (MIT)");
	}

	virtual int getNumInputs() 	{ return 0; }
	virtual int getNumOutputs() 	{ return 2; }
	static void classInit(int samplingFreq) {
		SIG0 sig0;
		sig0.init(samplingFreq);
		sig0.fill(65536,ftbl0);
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fslider0 = 0.137f;
		for (int i=0; i<2; i++) fRec0[i] = 0;
		fslider1 = 0.78f;
		fentry0 = 4.4e+02f;
		iConst0 = min(192000, max(1, fSamplingFreq));
		fConst1 = (6.283185307179586f / float(iConst0));
		iConst2 = (2 * iConst0);
		fslider2 = 0.041f;
		for (int i=0; i<2; i++) fVec0[i] = 0;
		fslider3 = 0.0f;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		fentry1 = 0.0f;
		fbutton0 = 0.0;
		for (int i=0; i<2; i++) iRec5[i] = 0;
		fslider4 = 0.07f;
		fslider5 = 0.1f;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		fslider6 = 2.2e+02f;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		fConst3 = float(iConst0);
		fConst4 = (1.0f / fConst3);
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		fslider7 = 6.0f;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) iRec23[i] = 0;
		for (int i=0; i<2; i++) iRec24[i] = 0;
		fslider8 = 0.1f;
		fslider9 = 0.05f;
		fslider10 = 0.5f;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		fslider11 = 0.05f;
		for (int i=0; i<2; i++) iRec26[i] = 0;
		fslider12 = 0.001f;
		fslider13 = 0.005f;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		fslider14 = 1.0f;
		for (int i=0; i<3; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		IOTA = 0;
		for (int i=0; i<8192; i++) fRec1[i] = 0;
		fslider15 = 0.6f;
		fentry2 = 1.0f;
		fConst5 = (1.0f / tanf((628.3185307179587f / float(iConst0))));
		fConst6 = (1 + fConst5);
		fConst7 = (1.0f / fConst6);
		fConst8 = (0 - ((1 - fConst5) / fConst6));
		for (int i=0; i<2; i++) fRec39[i] = 0;
		fslider16 = 0.72f;
		fConst9 = floorf((0.5f + (0.174713f * iConst0)));
		fConst10 = ((0 - (6.907755278982138f * fConst9)) / float(iConst0));
		fConst11 = (0.5f * fConst10);
		fConst12 = (0.3333333333333333f * fConst10);
		fConst13 = cosf((37699.11184307752f / fConst3));
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<8192; i++) fVec2[i] = 0;
		fConst14 = floorf((0.5f + (0.022904f * iConst0)));
		iConst15 = int((int((fConst9 - fConst14)) & 8191));
		for (int i=0; i<4096; i++) fVec3[i] = 0;
		iConst16 = int((int((0.02f * iConst0)) & 8191));
		for (int i=0; i<2048; i++) fVec4[i] = 0;
		iConst17 = int((int((fConst14 - 1)) & 2047));
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		fConst18 = floorf((0.5f + (0.153129f * iConst0)));
		fConst19 = ((0 - (6.907755278982138f * fConst18)) / float(iConst0));
		fConst20 = (0.5f * fConst19);
		fConst21 = (0.3333333333333333f * fConst19);
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<8192; i++) fVec5[i] = 0;
		fConst22 = floorf((0.5f + (0.020346f * iConst0)));
		iConst23 = int((int((fConst18 - fConst22)) & 8191));
		for (int i=0; i<1024; i++) fVec6[i] = 0;
		iConst24 = int((int((fConst22 - 1)) & 1023));
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		fConst25 = floorf((0.5f + (0.127837f * iConst0)));
		fConst26 = ((0 - (6.907755278982138f * fConst25)) / float(iConst0));
		fConst27 = (0.5f * fConst26);
		fConst28 = (0.3333333333333333f * fConst26);
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<8192; i++) fVec7[i] = 0;
		fConst29 = floorf((0.5f + (0.031604f * iConst0)));
		iConst30 = int((int((fConst25 - fConst29)) & 8191));
		for (int i=0; i<2048; i++) fVec8[i] = 0;
		iConst31 = int((int((fConst29 - 1)) & 2047));
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		fConst32 = floorf((0.5f + (0.125f * iConst0)));
		fConst33 = ((0 - (6.907755278982138f * fConst32)) / float(iConst0));
		fConst34 = (0.5f * fConst33);
		fConst35 = (0.3333333333333333f * fConst33);
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<8192; i++) fVec9[i] = 0;
		fConst36 = floorf((0.5f + (0.013458f * iConst0)));
		iConst37 = int((int((fConst32 - fConst36)) & 8191));
		for (int i=0; i<1024; i++) fVec10[i] = 0;
		iConst38 = int((int((fConst36 - 1)) & 1023));
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		fConst39 = floorf((0.5f + (0.210389f * iConst0)));
		fConst40 = ((0 - (6.907755278982138f * fConst39)) / float(iConst0));
		fConst41 = (0.5f * fConst40);
		fConst42 = (0.3333333333333333f * fConst40);
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<16384; i++) fVec11[i] = 0;
		fConst43 = floorf((0.5f + (0.024421f * iConst0)));
		iConst44 = int((int((fConst39 - fConst43)) & 16383));
		for (int i=0; i<4096; i++) fVec12[i] = 0;
		fslider17 = 0.5f;
		fConst45 = (0.5f * iConst0);
		for (int i=0; i<4096; i++) fVec13[i] = 0;
		for (int i=0; i<2048; i++) fVec14[i] = 0;
		iConst46 = int((int((fConst43 - 1)) & 2047));
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		fConst47 = floorf((0.5f + (0.192303f * iConst0)));
		fConst48 = ((0 - (6.907755278982138f * fConst47)) / float(iConst0));
		fConst49 = (0.5f * fConst48);
		fConst50 = (0.3333333333333333f * fConst48);
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<8192; i++) fVec15[i] = 0;
		fConst51 = floorf((0.5f + (0.029291f * iConst0)));
		iConst52 = int((int((fConst47 - fConst51)) & 8191));
		for (int i=0; i<2048; i++) fVec16[i] = 0;
		iConst53 = int((int((fConst51 - 1)) & 2047));
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		fConst54 = floorf((0.5f + (0.256891f * iConst0)));
		fConst55 = ((0 - (6.907755278982138f * fConst54)) / float(iConst0));
		fConst56 = (0.5f * fConst55);
		fConst57 = (0.3333333333333333f * fConst55);
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<16384; i++) fVec17[i] = 0;
		fConst58 = floorf((0.5f + (0.027333f * iConst0)));
		iConst59 = int((int((fConst54 - fConst58)) & 16383));
		for (int i=0; i<2048; i++) fVec18[i] = 0;
		iConst60 = int((int((fConst58 - 1)) & 2047));
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		fConst61 = floorf((0.5f + (0.219991f * iConst0)));
		fConst62 = ((0 - (6.907755278982138f * fConst61)) / float(iConst0));
		fConst63 = (0.5f * fConst62);
		fConst64 = (0.3333333333333333f * fConst62);
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<16384; i++) fVec19[i] = 0;
		fConst65 = floorf((0.5f + (0.019123f * iConst0)));
		iConst66 = int((int((fConst61 - fConst65)) & 16383));
		for (int i=0; i<1024; i++) fVec20[i] = 0;
		iConst67 = int((int((fConst65 - 1)) & 1023));
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<3; i++) fRec28[i] = 0;
		for (int i=0; i<3; i++) fRec29[i] = 0;
		for (int i=0; i<3; i++) fRec30[i] = 0;
		for (int i=0; i<3; i++) fRec31[i] = 0;
		for (int i=0; i<3; i++) fRec32[i] = 0;
		for (int i=0; i<3; i++) fRec33[i] = 0;
		for (int i=0; i<3; i++) fRec34[i] = 0;
		for (int i=0; i<3; i++) fRec35[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("0x00");
		interface->openHorizontalBox("Basic_Parameters");
		interface->declare(&fentry0, "1", "");
		interface->declare(&fentry0, "tooltip", "Tone frequency");
		interface->declare(&fentry0, "unit", "Hz");
		interface->addNumEntry("freq", &fentry0, 4.4e+02f, 2e+01f, 2e+04f, 1.0f);
		interface->declare(&fentry2, "1", "");
		interface->declare(&fentry2, "tooltip", "Gain (value between 0 and 1)");
		interface->addNumEntry("gain", &fentry2, 1.0f, 0.0f, 1.0f, 0.01f);
		interface->declare(&fbutton0, "1", "");
		interface->declare(&fbutton0, "tooltip", "noteOn = 1, noteOff = 0");
		interface->addButton("gate", &fbutton0);
		interface->closeBox();
		interface->openHorizontalBox("Envelopes_and_Vibrato");
		interface->openVerticalBox("Envelope_Parameters");
		interface->declare(&fslider13, "5", "");
		interface->declare(&fslider13, "tooltip", "Envelope attack duration");
		interface->declare(&fslider13, "unit", "s");
		interface->addHorizontalSlider("Envelope_Attack", &fslider13, 0.005f, 0.0f, 2.0f, 0.01f);
		interface->declare(&fslider12, "5", "");
		interface->declare(&fslider12, "tooltip", "Envelope decay duration");
		interface->declare(&fslider12, "unit", "s");
		interface->addHorizontalSlider("Envelope_Decay", &fslider12, 0.001f, 0.0f, 2.0f, 0.01f);
		interface->declare(&fslider4, "5", "");
		interface->declare(&fslider4, "tooltip", "Envelope release duration");
		interface->declare(&fslider4, "unit", "s");
		interface->addHorizontalSlider("Envelope_Release", &fslider4, 0.07f, 0.0f, 2.0f, 0.01f);
		interface->closeBox();
		interface->openVerticalBox("Vibrato_Parameters");
		interface->declare(&fslider10, "4", "");
		interface->declare(&fslider10, "tooltip", "Vibrato attack duration");
		interface->declare(&fslider10, "unit", "s");
		interface->addHorizontalSlider("Vibrato_Attack", &fslider10, 0.5f, 0.0f, 2.0f, 0.01f);
		interface->declare(&fslider9, "4", "");
		interface->declare(&fslider9, "tooltip", "Vibrato silence duration before attack");
		interface->declare(&fslider9, "unit", "s");
		interface->addHorizontalSlider("Vibrato_Begin", &fslider9, 0.05f, 0.0f, 2.0f, 0.01f);
		interface->declare(&fslider7, "4", "");
		interface->declare(&fslider7, "unit", "Hz");
		interface->addHorizontalSlider("Vibrato_Freq", &fslider7, 6.0f, 1.0f, 15.0f, 0.1f);
		interface->declare(&fslider11, "4", "");
		interface->declare(&fslider11, "tooltip", "A value between 0 and 1");
		interface->addHorizontalSlider("Vibrato_Gain", &fslider11, 0.05f, 0.0f, 1.0f, 0.01f);
		interface->declare(&fslider8, "4", "");
		interface->declare(&fslider8, "tooltip", "Vibrato release duration");
		interface->declare(&fslider8, "unit", "s");
		interface->addHorizontalSlider("Vibrato_Release", &fslider8, 0.1f, 0.0f, 2.0f, 0.01f);
		interface->closeBox();
		interface->closeBox();
		interface->openHorizontalBox("Physical_and_Nonlinearity");
		interface->openVerticalBox("Nonlinear_Filter_Parameters");
		interface->declare(&fslider6, "3", "");
		interface->declare(&fslider6, "tooltip", "Frequency of the sine wave for the modulation of theta (works if Modulation Type=3)");
		interface->declare(&fslider6, "unit", "Hz");
		interface->addHorizontalSlider("Modulation_Frequency", &fslider6, 2.2e+02f, 2e+01f, 1e+03f, 0.1f);
		interface->declare(&fentry1, "3", "");
		interface->declare(&fentry1, "tooltip", "0=theta is modulated by the incoming signal; 1=theta is modulated by the averaged incoming signal; 2=theta is modulated by the squared incoming signal; 3=theta is modulated by a sine wave of frequency freqMod; 4=theta is modulated by a sine wave of frequency freq;");
		interface->addNumEntry("Modulation_Type", &fentry1, 0.0f, 0.0f, 4.0f, 1.0f);
		interface->declare(&fslider3, "3", "");
		interface->declare(&fslider3, "tooltip", "Nonlinearity factor (value between 0 and 1)");
		interface->addHorizontalSlider("Nonlinearity", &fslider3, 0.0f, 0.0f, 1.0f, 0.01f);
		interface->declare(&fslider5, "3", "");
		interface->declare(&fslider5, "Attack duration of the nonlinearity", "");
		interface->declare(&fslider5, "unit", "s");
		interface->addHorizontalSlider("Nonlinearity_Attack", &fslider5, 0.1f, 0.0f, 2.0f, 0.01f);
		interface->closeBox();
		interface->openVerticalBox("Physical_Parameters");
		interface->declare(&fslider1, "2", "");
		interface->declare(&fslider1, "tooltip", "A value between 0 and 1");
		interface->addHorizontalSlider("Lip_Tension", &fslider1, 0.78f, 0.01f, 1.0f, 0.001f);
		interface->declare(&fslider14, "2", "");
		interface->declare(&fslider14, "tooltip", "A value between 0 and 1");
		interface->addHorizontalSlider("Pressure", &fslider14, 1.0f, 0.01f, 1.0f, 0.01f);
		interface->declare(&fslider2, "2", "");
		interface->declare(&fslider2, "tooltip", "A value between 0 and 1");
		interface->addHorizontalSlider("Slide_Length", &fslider2, 0.041f, 0.01f, 1.0f, 0.001f);
		interface->closeBox();
		interface->closeBox();
		interface->openVerticalBox("Reverb");
		interface->addHorizontalSlider("reverbGain", &fslider0, 0.137f, 0.0f, 1.0f, 0.01f);
		interface->addHorizontalSlider("roomSize", &fslider16, 0.72f, 0.01f, 2.0f, 0.01f);
		interface->closeBox();
		interface->openVerticalBox("Spat");
		interface->addHorizontalSlider("pan angle", &fslider15, 0.6f, 0.0f, 1.0f, 0.01f);
		interface->addHorizontalSlider("spatial width", &fslider17, 0.5f, 0.0f, 1.0f, 0.01f);
		interface->closeBox();
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (0.0010000000000000009f * float(fslider0));
		float 	fSlow1 = float(fentry0);
		float 	fSlow2 = (0 - (1.994f * cosf((fConst1 * (fSlow1 * powf(4,((2 * float(fslider1)) - 1)))))));
		float 	fSlow3 = ((0.5f + float(fslider2)) * (3 + (float(iConst2) / fSlow1)));
		int 	iSlow4 = int(fSlow3);
		int 	iSlow5 = (1 + iSlow4);
		int 	iSlow6 = int((1 + int((int(iSlow5) & 4095))));
		float 	fSlow7 = (fSlow3 - iSlow4);
		int 	iSlow8 = int((1 + int((iSlow4 & 4095))));
		float 	fSlow9 = (iSlow5 - fSlow3);
		float 	fSlow10 = (0.0010000000000000009f * float(fslider3));
		float 	fSlow11 = float(fentry1);
		float 	fSlow12 = (3.141592653589793f * (fSlow11 == 2));
		float 	fSlow13 = (1.5707963267948966f * (fSlow11 == 1));
		float 	fSlow14 = (3.141592653589793f * (fSlow11 == 0));
		float 	fSlow15 = float(fbutton0);
		int 	iSlow16 = (fSlow15 > 0);
		int 	iSlow17 = (fSlow15 <= 0);
		float 	fSlow18 = float(fslider4);
		float 	fSlow19 = (1 - (1.0f / powf(1e+05f,(1.0f / ((fSlow18 == 0.0f) + (iConst0 * fSlow18))))));
		float 	fSlow20 = float(fslider5);
		float 	fSlow21 = (1.0f / ((fSlow20 == 0.0f) + (iConst0 * fSlow20)));
		int 	iSlow22 = (fSlow11 < 3);
		float 	fSlow23 = (0.0010000000000000009f * float(fslider6));
		int 	iSlow24 = (fSlow11 != 4);
		float 	fSlow25 = (fSlow1 * (fSlow11 == 4));
		int 	iSlow26 = (fSlow11 >= 3);
		float 	fSlow27 = (fConst4 * float(fslider7));
		float 	fSlow28 = float(fslider8);
		float 	fSlow29 = (1 - (1.0f / powf(1e+05f,(1.0f / ((fSlow28 == 0.0f) + (iConst0 * fSlow28))))));
		float 	fSlow30 = float(fslider9);
		float 	fSlow31 = (iConst0 * fSlow30);
		float 	fSlow32 = ((fSlow30 == 0.0f) + fSlow31);
		float 	fSlow33 = float(fslider10);
		float 	fSlow34 = (1.0f / ((fSlow33 == 0.0f) + (iConst0 * fSlow33)));
		float 	fSlow35 = float(fslider11);
		float 	fSlow36 = float(fslider12);
		float 	fSlow37 = (1 - powf(1e+02f,(1.0f / ((fSlow36 == 0.0f) + (iConst0 * fSlow36)))));
		float 	fSlow38 = float(fslider13);
		float 	fSlow39 = (1.0f / ((fSlow38 == 0.0f) + (iConst0 * fSlow38)));
		float 	fSlow40 = float(fslider14);
		float 	fSlow41 = float(fslider15);
		float 	fSlow42 = float(fentry2);
		float 	fSlow43 = (4 * (fSlow42 * (1.0f - fSlow41)));
		float 	fSlow44 = float(fslider16);
		float 	fSlow45 = expf((fConst11 / fSlow44));
		float 	fSlow46 = ((expf((fConst12 / fSlow44)) / fSlow45) - 1);
		float 	fSlow47 = faustpower<2>(fSlow45);
		float 	fSlow48 = (1.0f - fSlow47);
		float 	fSlow49 = (1.0f - (fConst13 * fSlow47));
		float 	fSlow50 = (fSlow49 / fSlow48);
		float 	fSlow51 = sqrtf(max((float)0, ((faustpower<2>(fSlow49) / faustpower<2>(fSlow48)) - 1.0f)));
		float 	fSlow52 = (fSlow45 * ((1.0f + fSlow51) - fSlow50));
		float 	fSlow53 = (fSlow50 - fSlow51);
		float 	fSlow54 = expf((fConst20 / fSlow44));
		float 	fSlow55 = ((expf((fConst21 / fSlow44)) / fSlow54) - 1);
		float 	fSlow56 = faustpower<2>(fSlow54);
		float 	fSlow57 = (1.0f - fSlow56);
		float 	fSlow58 = (1.0f - (fConst13 * fSlow56));
		float 	fSlow59 = (fSlow58 / fSlow57);
		float 	fSlow60 = sqrtf(max((float)0, ((faustpower<2>(fSlow58) / faustpower<2>(fSlow57)) - 1.0f)));
		float 	fSlow61 = (fSlow54 * ((1.0f + fSlow60) - fSlow59));
		float 	fSlow62 = (fSlow59 - fSlow60);
		float 	fSlow63 = expf((fConst27 / fSlow44));
		float 	fSlow64 = ((expf((fConst28 / fSlow44)) / fSlow63) - 1);
		float 	fSlow65 = faustpower<2>(fSlow63);
		float 	fSlow66 = (1.0f - fSlow65);
		float 	fSlow67 = (1.0f - (fConst13 * fSlow65));
		float 	fSlow68 = (fSlow67 / fSlow66);
		float 	fSlow69 = sqrtf(max((float)0, ((faustpower<2>(fSlow67) / faustpower<2>(fSlow66)) - 1.0f)));
		float 	fSlow70 = (fSlow63 * ((1.0f + fSlow69) - fSlow68));
		float 	fSlow71 = (fSlow68 - fSlow69);
		float 	fSlow72 = expf((fConst34 / fSlow44));
		float 	fSlow73 = ((expf((fConst35 / fSlow44)) / fSlow72) - 1);
		float 	fSlow74 = faustpower<2>(fSlow72);
		float 	fSlow75 = (1.0f - fSlow74);
		float 	fSlow76 = (1.0f - (fConst13 * fSlow74));
		float 	fSlow77 = (fSlow76 / fSlow75);
		float 	fSlow78 = sqrtf(max((float)0, ((faustpower<2>(fSlow76) / faustpower<2>(fSlow75)) - 1.0f)));
		float 	fSlow79 = (fSlow72 * ((1.0f + fSlow78) - fSlow77));
		float 	fSlow80 = (fSlow77 - fSlow78);
		float 	fSlow81 = expf((fConst41 / fSlow44));
		float 	fSlow82 = ((expf((fConst42 / fSlow44)) / fSlow81) - 1);
		float 	fSlow83 = faustpower<2>(fSlow81);
		float 	fSlow84 = (1.0f - fSlow83);
		float 	fSlow85 = (1.0f - (fConst13 * fSlow83));
		float 	fSlow86 = (fSlow85 / fSlow84);
		float 	fSlow87 = sqrtf(max((float)0, ((faustpower<2>(fSlow85) / faustpower<2>(fSlow84)) - 1.0f)));
		float 	fSlow88 = (fSlow81 * ((1.0f + fSlow87) - fSlow86));
		float 	fSlow89 = (fSlow86 - fSlow87);
		float 	fSlow90 = (4 * fSlow42);
		int 	iSlow91 = int((int((fConst45 * (float(fslider17) / fSlow1))) & 4095));
		float 	fSlow92 = expf((fConst49 / fSlow44));
		float 	fSlow93 = ((expf((fConst50 / fSlow44)) / fSlow92) - 1);
		float 	fSlow94 = faustpower<2>(fSlow92);
		float 	fSlow95 = (1.0f - fSlow94);
		float 	fSlow96 = (1.0f - (fConst13 * fSlow94));
		float 	fSlow97 = (fSlow96 / fSlow95);
		float 	fSlow98 = sqrtf(max((float)0, ((faustpower<2>(fSlow96) / faustpower<2>(fSlow95)) - 1.0f)));
		float 	fSlow99 = (fSlow92 * ((1.0f + fSlow98) - fSlow97));
		float 	fSlow100 = (fSlow97 - fSlow98);
		float 	fSlow101 = expf((fConst56 / fSlow44));
		float 	fSlow102 = ((expf((fConst57 / fSlow44)) / fSlow101) - 1);
		float 	fSlow103 = faustpower<2>(fSlow101);
		float 	fSlow104 = (1.0f - fSlow103);
		float 	fSlow105 = (1.0f - (fConst13 * fSlow103));
		float 	fSlow106 = (fSlow105 / fSlow104);
		float 	fSlow107 = sqrtf(max((float)0, ((faustpower<2>(fSlow105) / faustpower<2>(fSlow104)) - 1.0f)));
		float 	fSlow108 = (fSlow101 * ((1.0f + fSlow107) - fSlow106));
		float 	fSlow109 = (fSlow106 - fSlow107);
		float 	fSlow110 = expf((fConst63 / fSlow44));
		float 	fSlow111 = ((expf((fConst64 / fSlow44)) / fSlow110) - 1);
		float 	fSlow112 = faustpower<2>(fSlow110);
		float 	fSlow113 = (1.0f - fSlow112);
		float 	fSlow114 = (1.0f - (fConst13 * fSlow112));
		float 	fSlow115 = (fSlow114 / fSlow113);
		float 	fSlow116 = sqrtf(max((float)0, ((faustpower<2>(fSlow114) / faustpower<2>(fSlow113)) - 1.0f)));
		float 	fSlow117 = (fSlow110 * ((1.0f + fSlow116) - fSlow115));
		float 	fSlow118 = (fSlow115 - fSlow116);
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			fRec0[0] = ((0.999f * fRec0[1]) + fSlow0);
			float fTemp0 = (1 - fRec0[0]);
			float fTemp1 = ((fSlow9 * fRec1[(IOTA-iSlow8)&8191]) + (fSlow7 * fRec1[(IOTA-iSlow6)&8191]));
			fVec0[0] = fTemp1;
			fRec4[0] = (fSlow10 + (0.999f * fRec4[1]));
			iRec5[0] = (iSlow16 & (iRec5[1] | (fRec6[1] >= 1)));
			int iTemp2 = (iSlow17 & (fRec6[1] > 0));
			fRec6[0] = (((fSlow21 * (((iRec5[1] == 0) & iSlow16) & (fRec6[1] < 1))) + (fRec6[1] * (1 - (fSlow19 * iTemp2)))) * ((iTemp2 == 0) | (fRec6[1] >= 1e-06f)));
			float fTemp3 = (fRec4[0] * fRec6[0]);
			float fTemp4 = (fTemp3 * (((fSlow14 * fVec0[0]) + (fSlow13 * (fVec0[0] + fVec0[1]))) + (fSlow12 * faustpower<2>(fVec0[0]))));
			float fTemp5 = cosf(fTemp4);
			float fTemp6 = sinf(fTemp4);
			float fTemp7 = (0 - fTemp6);
			float fTemp8 = ((fRec7[1] * fTemp7) + (fVec0[0] * fTemp5));
			float fTemp9 = ((fTemp7 * fRec8[1]) + (fTemp5 * fTemp8));
			float fTemp10 = ((fTemp7 * fRec9[1]) + (fTemp5 * fTemp9));
			float fTemp11 = ((fTemp7 * fRec10[1]) + (fTemp5 * fTemp10));
			float fTemp12 = ((fTemp7 * fRec11[1]) + (fTemp5 * fTemp11));
			fRec12[0] = ((fTemp7 * fRec12[1]) + (fTemp5 * fTemp12));
			fRec11[0] = ((fTemp6 * fTemp12) + (fTemp5 * fRec12[1]));
			fRec10[0] = ((fTemp6 * fTemp11) + (fTemp5 * fRec11[1]));
			fRec9[0] = ((fTemp6 * fTemp10) + (fTemp5 * fRec10[1]));
			fRec8[0] = ((fTemp6 * fTemp9) + (fTemp5 * fRec9[1]));
			fRec7[0] = ((fTemp6 * fTemp8) + (fTemp5 * fRec8[1]));
			fRec15[0] = (fSlow23 + (0.999f * fRec15[1]));
			float fTemp13 = (fRec14[1] + (fConst4 * (fSlow25 + (iSlow24 * fRec15[0]))));
			fRec14[0] = (fTemp13 - floorf(fTemp13));
			float fTemp14 = (3.141592653589793f * (fTemp3 * ftbl0[int((65536.0f * fRec14[0]))]));
			float fTemp15 = cosf(fTemp14);
			float fTemp16 = sinf(fTemp14);
			float fTemp17 = (0 - fTemp16);
			float fTemp18 = ((fRec16[1] * fTemp17) + (fVec0[0] * fTemp15));
			float fTemp19 = ((fTemp17 * fRec17[1]) + (fTemp15 * fTemp18));
			float fTemp20 = ((fTemp17 * fRec18[1]) + (fTemp15 * fTemp19));
			float fTemp21 = ((fTemp17 * fRec19[1]) + (fTemp15 * fTemp20));
			float fTemp22 = ((fTemp17 * fRec20[1]) + (fTemp15 * fTemp21));
			fRec21[0] = ((fTemp17 * fRec21[1]) + (fTemp15 * fTemp22));
			fRec20[0] = ((fTemp16 * fTemp22) + (fTemp15 * fRec21[1]));
			fRec19[0] = ((fTemp16 * fTemp21) + (fTemp15 * fRec20[1]));
			fRec18[0] = ((fTemp16 * fTemp20) + (fTemp15 * fRec19[1]));
			fRec17[0] = ((fTemp16 * fTemp19) + (fTemp15 * fRec18[1]));
			fRec16[0] = ((fTemp16 * fTemp18) + (fTemp15 * fRec17[1]));
			float fTemp23 = ((iSlow26 * ((fVec0[0] * fTemp16) + (fRec16[1] * fTemp15))) + (iSlow22 * ((fRec4[0] * ((fVec0[0] * fTemp6) + (fRec7[1] * fTemp5))) + ((1 - fRec4[0]) * fVec0[0]))));
			float fTemp24 = (fRec22[1] + fSlow27);
			fRec22[0] = (fTemp24 - floorf(fTemp24));
			iRec23[0] = (iSlow16 & (iRec23[1] | (fRec25[1] >= 1)));
			iRec24[0] = (iSlow16 * (1 + iRec24[1]));
			int iTemp25 = (iSlow17 & (fRec25[1] > 0));
			fRec25[0] = (((fSlow34 * (((((iRec23[1] == 0) & iSlow16) & (fRec25[1] < 1)) & (iRec24[1] > fSlow31)) * (1 - (iRec24[1] < fSlow32)))) + (fRec25[1] * (1 - (fSlow29 * iTemp25)))) * ((iTemp25 == 0) | (fRec25[1] >= 1e-06f)));
			iRec26[0] = (iSlow16 & (iRec26[1] | (fRec27[1] >= 1)));
			int iTemp26 = (iSlow17 & (fRec27[1] > 0));
			fRec27[0] = (((fSlow39 * (((iRec26[1] == 0) & iSlow16) & (fRec27[1] < 1))) + (fRec27[1] * ((1 - (fSlow37 * (iRec26[1] & (fRec27[1] > 100)))) - (fSlow19 * iTemp26)))) * ((iTemp26 == 0) | (fRec27[1] >= 1e-06f)));
			float fTemp27 = ((fSlow40 * fRec27[0]) + (fSlow35 * (fRec25[0] * ftbl0[int((65536.0f * fRec22[0]))])));
			fRec3[0] = ((0.03f * ((0.3f * fTemp27) - (0.85f * fTemp23))) - ((fSlow2 * fRec3[1]) + (0.994009f * fRec3[2])));
			float fTemp28 = faustpower<2>(fRec3[0]);
			float fTemp29 = ((fTemp28 > 1) + (fTemp28 * (fTemp28 <= 1)));
			float fTemp30 = (0.85f * (fTemp23 * (0 - (fTemp29 - 1))));
			float fTemp31 = (0.3f * (fTemp27 * fTemp29));
			fVec1[0] = (fTemp31 + fTemp30);
			fRec2[0] = ((fTemp30 + ((0.995f * fRec2[1]) + fTemp31)) - fVec1[1]);
			fRec1[IOTA&8191] = fRec2[0];
			float fTemp32 = fRec1[(IOTA-0)&8191];
			fRec39[0] = ((fConst8 * fRec39[1]) + (fConst7 * (fRec32[1] + fRec32[2])));
			fRec38[0] = ((fSlow53 * fRec38[1]) + (fSlow52 * (fRec32[1] + (fSlow46 * fRec39[0]))));
			fVec2[IOTA&8191] = (1e-20f + (0.35355339059327373f * fRec38[0]));
			fVec3[IOTA&4095] = (fSlow43 * (fTemp32 * fRec0[0]));
			float fTemp33 = (0.3f * fVec3[(IOTA-iConst16)&4095]);
			float fTemp34 = ((fTemp33 + fVec2[(IOTA-iConst15)&8191]) - (0.6f * fRec36[1]));
			fVec4[IOTA&2047] = fTemp34;
			fRec36[0] = fVec4[(IOTA-iConst17)&2047];
			float 	fRec37 = (0.6f * fVec4[IOTA&2047]);
			fRec43[0] = ((fConst8 * fRec43[1]) + (fConst7 * (fRec28[1] + fRec28[2])));
			fRec42[0] = ((fSlow62 * fRec42[1]) + (fSlow61 * (fRec28[1] + (fSlow55 * fRec43[0]))));
			fVec5[IOTA&8191] = (1e-20f + (0.35355339059327373f * fRec42[0]));
			float fTemp35 = ((fVec5[(IOTA-iConst23)&8191] + fTemp33) - (0.6f * fRec40[1]));
			fVec6[IOTA&1023] = fTemp35;
			fRec40[0] = fVec6[(IOTA-iConst24)&1023];
			float 	fRec41 = (0.6f * fVec6[IOTA&1023]);
			float fTemp36 = (fRec41 + fRec37);
			fRec47[0] = ((fConst8 * fRec47[1]) + (fConst7 * (fRec30[1] + fRec30[2])));
			fRec46[0] = ((fSlow71 * fRec46[1]) + (fSlow70 * (fRec30[1] + (fSlow64 * fRec47[0]))));
			fVec7[IOTA&8191] = (1e-20f + (0.35355339059327373f * fRec46[0]));
			float fTemp37 = (fVec7[(IOTA-iConst30)&8191] - (fTemp33 + (0.6f * fRec44[1])));
			fVec8[IOTA&2047] = fTemp37;
			fRec44[0] = fVec8[(IOTA-iConst31)&2047];
			float 	fRec45 = (0.6f * fVec8[IOTA&2047]);
			fRec51[0] = ((fConst8 * fRec51[1]) + (fConst7 * (fRec34[1] + fRec34[2])));
			fRec50[0] = ((fSlow80 * fRec50[1]) + (fSlow79 * (fRec34[1] + (fSlow73 * fRec51[0]))));
			fVec9[IOTA&8191] = (1e-20f + (0.35355339059327373f * fRec50[0]));
			float fTemp38 = (fVec9[(IOTA-iConst37)&8191] - (fTemp33 + (0.6f * fRec48[1])));
			fVec10[IOTA&1023] = fTemp38;
			fRec48[0] = fVec10[(IOTA-iConst38)&1023];
			float 	fRec49 = (0.6f * fVec10[IOTA&1023]);
			float fTemp39 = (fRec49 + (fRec45 + fTemp36));
			fRec55[0] = ((fConst8 * fRec55[1]) + (fConst7 * (fRec29[1] + fRec29[2])));
			fRec54[0] = ((fSlow89 * fRec54[1]) + (fSlow88 * (fRec29[1] + (fSlow82 * fRec55[0]))));
			fVec11[IOTA&16383] = (1e-20f + (0.35355339059327373f * fRec54[0]));
			fVec12[IOTA&4095] = (fSlow90 * fTemp32);
			float fTemp40 = fVec12[(IOTA-iSlow91)&4095];
			fVec13[IOTA&4095] = (fSlow41 * (fRec0[0] * fTemp40));
			float fTemp41 = (0.3f * fVec13[(IOTA-iConst16)&4095]);
			float fTemp42 = (fTemp41 + ((0.6f * fRec52[1]) + fVec11[(IOTA-iConst44)&16383]));
			fVec14[IOTA&2047] = fTemp42;
			fRec52[0] = fVec14[(IOTA-iConst46)&2047];
			float 	fRec53 = (0 - (0.6f * fVec14[IOTA&2047]));
			fRec59[0] = ((fConst8 * fRec59[1]) + (fConst7 * (fRec33[1] + fRec33[2])));
			fRec58[0] = ((fSlow100 * fRec58[1]) + (fSlow99 * (fRec33[1] + (fSlow93 * fRec59[0]))));
			fVec15[IOTA&8191] = (1e-20f + (0.35355339059327373f * fRec58[0]));
			float fTemp43 = (fVec15[(IOTA-iConst52)&8191] + (fTemp41 + (0.6f * fRec56[1])));
			fVec16[IOTA&2047] = fTemp43;
			fRec56[0] = fVec16[(IOTA-iConst53)&2047];
			float 	fRec57 = (0 - (0.6f * fVec16[IOTA&2047]));
			fRec63[0] = ((fConst8 * fRec63[1]) + (fConst7 * (fRec31[1] + fRec31[2])));
			fRec62[0] = ((fSlow109 * fRec62[1]) + (fSlow108 * (fRec31[1] + (fSlow102 * fRec63[0]))));
			fVec17[IOTA&16383] = (1e-20f + (0.35355339059327373f * fRec62[0]));
			float fTemp44 = (((0.6f * fRec60[1]) + fVec17[(IOTA-iConst59)&16383]) - fTemp41);
			fVec18[IOTA&2047] = fTemp44;
			fRec60[0] = fVec18[(IOTA-iConst60)&2047];
			float 	fRec61 = (0 - (0.6f * fVec18[IOTA&2047]));
			fRec67[0] = ((fConst8 * fRec67[1]) + (fConst7 * (fRec35[1] + fRec35[2])));
			fRec66[0] = ((fSlow118 * fRec66[1]) + (fSlow117 * (fRec35[1] + (fSlow111 * fRec67[0]))));
			fVec19[IOTA&16383] = (1e-20f + (0.35355339059327373f * fRec66[0]));
			float fTemp45 = (((0.6f * fRec64[1]) + fVec19[(IOTA-iConst66)&16383]) - fTemp41);
			fVec20[IOTA&1023] = fTemp45;
			fRec64[0] = fVec20[(IOTA-iConst67)&1023];
			float 	fRec65 = (0 - (0.6f * fVec20[IOTA&1023]));
			fRec28[0] = (fRec64[1] + (fRec60[1] + (fRec56[1] + (fRec52[1] + (fRec48[1] + (fRec44[1] + (fRec36[1] + (fRec40[1] + (fRec65 + (fRec61 + (fRec57 + (fRec53 + fTemp39))))))))))));
			fRec29[0] = (0 - ((fRec64[1] + (fRec60[1] + (fRec56[1] + (fRec52[1] + (fRec65 + (fRec61 + (fRec53 + fRec57))))))) - (fRec48[1] + (fRec44[1] + (fRec36[1] + (fRec40[1] + fTemp39))))));
			float fTemp46 = (fRec45 + fRec49);
			fRec30[0] = (0 - ((fRec64[1] + (fRec60[1] + (fRec48[1] + (fRec44[1] + (fRec65 + (fRec61 + fTemp46)))))) - (fRec56[1] + (fRec52[1] + (fRec36[1] + (fRec40[1] + (fRec57 + (fRec53 + fTemp36))))))));
			fRec31[0] = (0 - ((fRec56[1] + (fRec52[1] + (fRec48[1] + (fRec44[1] + (fRec57 + (fRec53 + fTemp46)))))) - (fRec64[1] + (fRec60[1] + (fRec36[1] + (fRec40[1] + (fRec65 + (fRec61 + fTemp36))))))));
			float fTemp47 = (fRec41 + fRec45);
			float fTemp48 = (fRec37 + fRec49);
			fRec32[0] = (0 - ((fRec64[1] + (fRec56[1] + (fRec48[1] + (fRec36[1] + (fRec65 + (fRec57 + fTemp48)))))) - (fRec60[1] + (fRec52[1] + (fRec44[1] + (fRec40[1] + (fRec61 + (fRec53 + fTemp47))))))));
			fRec33[0] = (0 - ((fRec60[1] + (fRec52[1] + (fRec48[1] + (fRec36[1] + (fRec61 + (fRec53 + fTemp48)))))) - (fRec64[1] + (fRec56[1] + (fRec44[1] + (fRec40[1] + (fRec65 + (fRec57 + fTemp47))))))));
			float fTemp49 = (fRec41 + fRec49);
			float fTemp50 = (fRec37 + fRec45);
			fRec34[0] = (0 - ((fRec60[1] + (fRec56[1] + (fRec44[1] + (fRec36[1] + (fRec61 + (fRec57 + fTemp50)))))) - (fRec64[1] + (fRec52[1] + (fRec48[1] + (fRec40[1] + (fRec65 + (fRec53 + fTemp49))))))));
			fRec35[0] = (0 - ((fRec64[1] + (fRec52[1] + (fRec44[1] + (fRec36[1] + (fRec65 + (fRec53 + fTemp50)))))) - (fRec60[1] + (fRec56[1] + (fRec48[1] + (fRec40[1] + (fRec61 + (fRec57 + fTemp49))))))));
			output0[i] = (FAUSTFLOAT)((0.37f * (fRec29[0] + fRec30[0])) + (fSlow43 * (fTemp32 * fTemp0)));
			output1[i] = (FAUSTFLOAT)((0.37f * (fRec29[0] - fRec30[0])) + (fSlow41 * (fTemp0 * fTemp40)));
			// post processing
			fRec35[2] = fRec35[1]; fRec35[1] = fRec35[0];
			fRec34[2] = fRec34[1]; fRec34[1] = fRec34[0];
			fRec33[2] = fRec33[1]; fRec33[1] = fRec33[0];
			fRec32[2] = fRec32[1]; fRec32[1] = fRec32[0];
			fRec31[2] = fRec31[1]; fRec31[1] = fRec31[0];
			fRec30[2] = fRec30[1]; fRec30[1] = fRec30[0];
			fRec29[2] = fRec29[1]; fRec29[1] = fRec29[0];
			fRec28[2] = fRec28[1]; fRec28[1] = fRec28[0];
			fRec64[1] = fRec64[0];
			fRec66[1] = fRec66[0];
			fRec67[1] = fRec67[0];
			fRec60[1] = fRec60[0];
			fRec62[1] = fRec62[0];
			fRec63[1] = fRec63[0];
			fRec56[1] = fRec56[0];
			fRec58[1] = fRec58[0];
			fRec59[1] = fRec59[0];
			fRec52[1] = fRec52[0];
			fRec54[1] = fRec54[0];
			fRec55[1] = fRec55[0];
			fRec48[1] = fRec48[0];
			fRec50[1] = fRec50[0];
			fRec51[1] = fRec51[0];
			fRec44[1] = fRec44[0];
			fRec46[1] = fRec46[0];
			fRec47[1] = fRec47[0];
			fRec40[1] = fRec40[0];
			fRec42[1] = fRec42[0];
			fRec43[1] = fRec43[0];
			fRec36[1] = fRec36[0];
			fRec38[1] = fRec38[0];
			fRec39[1] = fRec39[0];
			IOTA = IOTA+1;
			fRec2[1] = fRec2[0];
			fVec1[1] = fVec1[0];
			fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
			fRec27[1] = fRec27[0];
			iRec26[1] = iRec26[0];
			fRec25[1] = fRec25[0];
			iRec24[1] = iRec24[0];
			iRec23[1] = iRec23[0];
			fRec22[1] = fRec22[0];
			fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			fRec18[1] = fRec18[0];
			fRec19[1] = fRec19[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			fRec6[1] = fRec6[0];
			iRec5[1] = iRec5[0];
			fRec4[1] = fRec4[0];
			fVec0[1] = fVec0[0];
			fRec0[1] = fRec0[0];
		}
	}
};


float 	mydsp::ftbl0[65536];