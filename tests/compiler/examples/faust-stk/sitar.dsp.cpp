//-----------------------------------------------------
// name: "Sitar"
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
	FAUSTFLOAT 	fslider0;
	float 	fRec0[2];
	int 	iRec3[2];
	float 	fRec2[2];
	FAUSTFLOAT 	fentry0;
	int 	iConst0;
	FAUSTFLOAT 	fslider1;
	float 	fVec0[2];
	FAUSTFLOAT 	fbutton0;
	int 	iRec4[2];
	float 	fConst1;
	float 	fConst2;
	float 	fConst3;
	float 	fRec5[2];
	FAUSTFLOAT 	fentry1;
	int 	IOTA;
	float 	fRec1[8192];
	FAUSTFLOAT 	fslider2;
	float 	fConst4;
	float 	fConst5;
	float 	fConst6;
	float 	fConst7;
	float 	fRec17[2];
	FAUSTFLOAT 	fslider3;
	float 	fConst8;
	float 	fConst9;
	float 	fConst10;
	float 	fConst11;
	float 	fConst12;
	float 	fRec16[2];
	float 	fVec1[8192];
	float 	fConst13;
	int 	iConst14;
	float 	fVec2[4096];
	int 	iConst15;
	float 	fVec3[2048];
	int 	iConst16;
	float 	fRec14[2];
	float 	fRec21[2];
	float 	fConst17;
	float 	fConst18;
	float 	fConst19;
	float 	fConst20;
	float 	fRec20[2];
	float 	fVec4[8192];
	float 	fConst21;
	int 	iConst22;
	float 	fVec5[1024];
	int 	iConst23;
	float 	fRec18[2];
	float 	fRec25[2];
	float 	fConst24;
	float 	fConst25;
	float 	fConst26;
	float 	fConst27;
	float 	fRec24[2];
	float 	fVec6[8192];
	float 	fConst28;
	int 	iConst29;
	float 	fVec7[2048];
	int 	iConst30;
	float 	fRec22[2];
	float 	fRec29[2];
	float 	fConst31;
	float 	fConst32;
	float 	fConst33;
	float 	fConst34;
	float 	fRec28[2];
	float 	fVec8[8192];
	float 	fConst35;
	int 	iConst36;
	float 	fVec9[1024];
	int 	iConst37;
	float 	fRec26[2];
	float 	fRec33[2];
	float 	fConst38;
	float 	fConst39;
	float 	fConst40;
	float 	fConst41;
	float 	fRec32[2];
	float 	fVec10[16384];
	float 	fConst42;
	int 	iConst43;
	FAUSTFLOAT 	fslider4;
	float 	fConst44;
	float 	fVec11[4096];
	float 	fVec12[2048];
	int 	iConst45;
	float 	fRec30[2];
	float 	fRec37[2];
	float 	fConst46;
	float 	fConst47;
	float 	fConst48;
	float 	fConst49;
	float 	fRec36[2];
	float 	fVec13[8192];
	float 	fConst50;
	int 	iConst51;
	float 	fVec14[2048];
	int 	iConst52;
	float 	fRec34[2];
	float 	fRec41[2];
	float 	fConst53;
	float 	fConst54;
	float 	fConst55;
	float 	fConst56;
	float 	fRec40[2];
	float 	fVec15[16384];
	float 	fConst57;
	int 	iConst58;
	float 	fVec16[2048];
	int 	iConst59;
	float 	fRec38[2];
	float 	fRec45[2];
	float 	fConst60;
	float 	fConst61;
	float 	fConst62;
	float 	fConst63;
	float 	fRec44[2];
	float 	fVec17[16384];
	float 	fConst64;
	int 	iConst65;
	float 	fVec18[1024];
	int 	iConst66;
	float 	fRec42[2];
	float 	fRec6[3];
	float 	fRec7[3];
	float 	fRec8[3];
	float 	fRec9[3];
	float 	fRec10[3];
	float 	fRec11[3];
	float 	fRec12[3];
	float 	fRec13[3];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "Sitar");
		m->declare("description", "WaveGuide Sitar");
		m->declare("author", "Romain Michon (rmichon@ccrma.stanford.edu)");
		m->declare("copyright", "Romain Michon");
		m->declare("version", "1.0");
		m->declare("licence", "STK-4.3");
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
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fslider0 = 0.137f;
		for (int i=0; i<2; i++) fRec0[i] = 0;
		for (int i=0; i<2; i++) iRec3[i] = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		fentry0 = 4.4e+02f;
		iConst0 = min(192000, max(1, fSamplingFreq));
		fslider1 = 0.7f;
		for (int i=0; i<2; i++) fVec0[i] = 0;
		fbutton0 = 0.0;
		for (int i=0; i<2; i++) iRec4[i] = 0;
		fConst1 = (1 - (1.0f / powf(1.0f,(2.0f / float(iConst0)))));
		fConst2 = (1 - powf(0.001f,(25.0f / float(iConst0))));
		fConst3 = (1e+03f / float(iConst0));
		for (int i=0; i<2; i++) fRec5[i] = 0;
		fentry1 = 1.0f;
		IOTA = 0;
		for (int i=0; i<8192; i++) fRec1[i] = 0;
		fslider2 = 0.6f;
		fConst4 = (1.0f / tanf((628.3185307179587f / float(iConst0))));
		fConst5 = (1 + fConst4);
		fConst6 = (1.0f / fConst5);
		fConst7 = (0 - ((1 - fConst4) / fConst5));
		for (int i=0; i<2; i++) fRec17[i] = 0;
		fslider3 = 0.72f;
		fConst8 = floorf((0.5f + (0.174713f * iConst0)));
		fConst9 = ((0 - (6.907755278982138f * fConst8)) / float(iConst0));
		fConst10 = (0.5f * fConst9);
		fConst11 = (0.3333333333333333f * fConst9);
		fConst12 = cosf((37699.11184307752f / float(iConst0)));
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<8192; i++) fVec1[i] = 0;
		fConst13 = floorf((0.5f + (0.022904f * iConst0)));
		iConst14 = int((int((fConst8 - fConst13)) & 8191));
		for (int i=0; i<4096; i++) fVec2[i] = 0;
		iConst15 = int((int((0.02f * iConst0)) & 8191));
		for (int i=0; i<2048; i++) fVec3[i] = 0;
		iConst16 = int((int((fConst13 - 1)) & 2047));
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		fConst17 = floorf((0.5f + (0.153129f * iConst0)));
		fConst18 = ((0 - (6.907755278982138f * fConst17)) / float(iConst0));
		fConst19 = (0.5f * fConst18);
		fConst20 = (0.3333333333333333f * fConst18);
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<8192; i++) fVec4[i] = 0;
		fConst21 = floorf((0.5f + (0.020346f * iConst0)));
		iConst22 = int((int((fConst17 - fConst21)) & 8191));
		for (int i=0; i<1024; i++) fVec5[i] = 0;
		iConst23 = int((int((fConst21 - 1)) & 1023));
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		fConst24 = floorf((0.5f + (0.127837f * iConst0)));
		fConst25 = ((0 - (6.907755278982138f * fConst24)) / float(iConst0));
		fConst26 = (0.5f * fConst25);
		fConst27 = (0.3333333333333333f * fConst25);
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<8192; i++) fVec6[i] = 0;
		fConst28 = floorf((0.5f + (0.031604f * iConst0)));
		iConst29 = int((int((fConst24 - fConst28)) & 8191));
		for (int i=0; i<2048; i++) fVec7[i] = 0;
		iConst30 = int((int((fConst28 - 1)) & 2047));
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		fConst31 = floorf((0.5f + (0.125f * iConst0)));
		fConst32 = ((0 - (6.907755278982138f * fConst31)) / float(iConst0));
		fConst33 = (0.5f * fConst32);
		fConst34 = (0.3333333333333333f * fConst32);
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<8192; i++) fVec8[i] = 0;
		fConst35 = floorf((0.5f + (0.013458f * iConst0)));
		iConst36 = int((int((fConst31 - fConst35)) & 8191));
		for (int i=0; i<1024; i++) fVec9[i] = 0;
		iConst37 = int((int((fConst35 - 1)) & 1023));
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		fConst38 = floorf((0.5f + (0.210389f * iConst0)));
		fConst39 = ((0 - (6.907755278982138f * fConst38)) / float(iConst0));
		fConst40 = (0.5f * fConst39);
		fConst41 = (0.3333333333333333f * fConst39);
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<16384; i++) fVec10[i] = 0;
		fConst42 = floorf((0.5f + (0.024421f * iConst0)));
		iConst43 = int((int((fConst38 - fConst42)) & 16383));
		fslider4 = 0.5f;
		fConst44 = (0.5f * iConst0);
		for (int i=0; i<4096; i++) fVec11[i] = 0;
		for (int i=0; i<2048; i++) fVec12[i] = 0;
		iConst45 = int((int((fConst42 - 1)) & 2047));
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		fConst46 = floorf((0.5f + (0.192303f * iConst0)));
		fConst47 = ((0 - (6.907755278982138f * fConst46)) / float(iConst0));
		fConst48 = (0.5f * fConst47);
		fConst49 = (0.3333333333333333f * fConst47);
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<8192; i++) fVec13[i] = 0;
		fConst50 = floorf((0.5f + (0.029291f * iConst0)));
		iConst51 = int((int((fConst46 - fConst50)) & 8191));
		for (int i=0; i<2048; i++) fVec14[i] = 0;
		iConst52 = int((int((fConst50 - 1)) & 2047));
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		fConst53 = floorf((0.5f + (0.256891f * iConst0)));
		fConst54 = ((0 - (6.907755278982138f * fConst53)) / float(iConst0));
		fConst55 = (0.5f * fConst54);
		fConst56 = (0.3333333333333333f * fConst54);
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<16384; i++) fVec15[i] = 0;
		fConst57 = floorf((0.5f + (0.027333f * iConst0)));
		iConst58 = int((int((fConst53 - fConst57)) & 16383));
		for (int i=0; i<2048; i++) fVec16[i] = 0;
		iConst59 = int((int((fConst57 - 1)) & 2047));
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		fConst60 = floorf((0.5f + (0.219991f * iConst0)));
		fConst61 = ((0 - (6.907755278982138f * fConst60)) / float(iConst0));
		fConst62 = (0.5f * fConst61);
		fConst63 = (0.3333333333333333f * fConst61);
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<16384; i++) fVec17[i] = 0;
		fConst64 = floorf((0.5f + (0.019123f * iConst0)));
		iConst65 = int((int((fConst60 - fConst64)) & 16383));
		for (int i=0; i<1024; i++) fVec18[i] = 0;
		iConst66 = int((int((fConst64 - 1)) & 1023));
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<3; i++) fRec6[i] = 0;
		for (int i=0; i<3; i++) fRec7[i] = 0;
		for (int i=0; i<3; i++) fRec8[i] = 0;
		for (int i=0; i<3; i++) fRec9[i] = 0;
		for (int i=0; i<3; i++) fRec10[i] = 0;
		for (int i=0; i<3; i++) fRec11[i] = 0;
		for (int i=0; i<3; i++) fRec12[i] = 0;
		for (int i=0; i<3; i++) fRec13[i] = 0;
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
		interface->declare(&fentry1, "1", "");
		interface->declare(&fentry1, "tooltip", "Gain (value between 0 and 1)");
		interface->addNumEntry("gain", &fentry1, 1.0f, 0.0f, 1.0f, 0.01f);
		interface->declare(&fbutton0, "1", "");
		interface->declare(&fbutton0, "tooltip", "noteOn = 1, noteOff = 0");
		interface->addButton("gate", &fbutton0);
		interface->closeBox();
		interface->openVerticalBox("Physical_Parameters");
		interface->declare(&fslider1, "2", "");
		interface->declare(&fslider1, "tooltip", "A value between 0 and 1");
		interface->addHorizontalSlider("Resonance", &fslider1, 0.7f, 0.0f, 1.0f, 0.01f);
		interface->closeBox();
		interface->openVerticalBox("Reverb");
		interface->addHorizontalSlider("reverbGain", &fslider0, 0.137f, 0.0f, 1.0f, 0.01f);
		interface->addHorizontalSlider("roomSize", &fslider3, 0.72f, 0.01f, 2.0f, 0.01f);
		interface->closeBox();
		interface->openVerticalBox("Spat");
		interface->addHorizontalSlider("pan angle", &fslider2, 0.6f, 0.0f, 1.0f, 0.01f);
		interface->addHorizontalSlider("spatial width", &fslider4, 0.5f, 0.0f, 1.0f, 0.01f);
		interface->closeBox();
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (0.0010000000000000009f * float(fslider0));
		float 	fSlow1 = float(fentry0);
		float 	fSlow2 = (float(iConst0) / fSlow1);
		float 	fSlow3 = (0.895f + ((0.1f * float(fslider1)) + (5e-07f * fSlow1)));
		float 	fSlow4 = float(fbutton0);
		int 	iSlow5 = (fSlow4 > 0);
		int 	iSlow6 = (fSlow4 <= 0);
		float 	fSlow7 = (4.656612875245797e-11f * float(fentry1));
		float 	fSlow8 = (0.9900990099009901f * fSlow3);
		float 	fSlow9 = float(fslider2);
		float 	fSlow10 = (8 * (1.0f - fSlow9));
		float 	fSlow11 = float(fslider3);
		float 	fSlow12 = expf((fConst10 / fSlow11));
		float 	fSlow13 = ((expf((fConst11 / fSlow11)) / fSlow12) - 1);
		float 	fSlow14 = faustpower<2>(fSlow12);
		float 	fSlow15 = (1.0f - fSlow14);
		float 	fSlow16 = (1.0f - (fConst12 * fSlow14));
		float 	fSlow17 = (fSlow16 / fSlow15);
		float 	fSlow18 = sqrtf(max((float)0, ((faustpower<2>(fSlow16) / faustpower<2>(fSlow15)) - 1.0f)));
		float 	fSlow19 = (fSlow12 * ((1.0f + fSlow18) - fSlow17));
		float 	fSlow20 = (fSlow17 - fSlow18);
		float 	fSlow21 = expf((fConst19 / fSlow11));
		float 	fSlow22 = ((expf((fConst20 / fSlow11)) / fSlow21) - 1);
		float 	fSlow23 = faustpower<2>(fSlow21);
		float 	fSlow24 = (1.0f - fSlow23);
		float 	fSlow25 = (1.0f - (fConst12 * fSlow23));
		float 	fSlow26 = (fSlow25 / fSlow24);
		float 	fSlow27 = sqrtf(max((float)0, ((faustpower<2>(fSlow25) / faustpower<2>(fSlow24)) - 1.0f)));
		float 	fSlow28 = (fSlow21 * ((1.0f + fSlow27) - fSlow26));
		float 	fSlow29 = (fSlow26 - fSlow27);
		float 	fSlow30 = expf((fConst26 / fSlow11));
		float 	fSlow31 = ((expf((fConst27 / fSlow11)) / fSlow30) - 1);
		float 	fSlow32 = faustpower<2>(fSlow30);
		float 	fSlow33 = (1.0f - fSlow32);
		float 	fSlow34 = (1.0f - (fConst12 * fSlow32));
		float 	fSlow35 = (fSlow34 / fSlow33);
		float 	fSlow36 = sqrtf(max((float)0, ((faustpower<2>(fSlow34) / faustpower<2>(fSlow33)) - 1.0f)));
		float 	fSlow37 = (fSlow30 * ((1.0f + fSlow36) - fSlow35));
		float 	fSlow38 = (fSlow35 - fSlow36);
		float 	fSlow39 = expf((fConst33 / fSlow11));
		float 	fSlow40 = ((expf((fConst34 / fSlow11)) / fSlow39) - 1);
		float 	fSlow41 = faustpower<2>(fSlow39);
		float 	fSlow42 = (1.0f - fSlow41);
		float 	fSlow43 = (1.0f - (fConst12 * fSlow41));
		float 	fSlow44 = (fSlow43 / fSlow42);
		float 	fSlow45 = sqrtf(max((float)0, ((faustpower<2>(fSlow43) / faustpower<2>(fSlow42)) - 1.0f)));
		float 	fSlow46 = (fSlow39 * ((1.0f + fSlow45) - fSlow44));
		float 	fSlow47 = (fSlow44 - fSlow45);
		float 	fSlow48 = expf((fConst40 / fSlow11));
		float 	fSlow49 = ((expf((fConst41 / fSlow11)) / fSlow48) - 1);
		float 	fSlow50 = faustpower<2>(fSlow48);
		float 	fSlow51 = (1.0f - fSlow50);
		float 	fSlow52 = (1.0f - (fConst12 * fSlow50));
		float 	fSlow53 = (fSlow52 / fSlow51);
		float 	fSlow54 = sqrtf(max((float)0, ((faustpower<2>(fSlow52) / faustpower<2>(fSlow51)) - 1.0f)));
		float 	fSlow55 = (fSlow48 * ((1.0f + fSlow54) - fSlow53));
		float 	fSlow56 = (fSlow53 - fSlow54);
		int 	iSlow57 = int((int((fConst44 * (float(fslider4) / fSlow1))) & 4095));
		float 	fSlow58 = (8 * fSlow9);
		float 	fSlow59 = expf((fConst48 / fSlow11));
		float 	fSlow60 = ((expf((fConst49 / fSlow11)) / fSlow59) - 1);
		float 	fSlow61 = faustpower<2>(fSlow59);
		float 	fSlow62 = (1.0f - fSlow61);
		float 	fSlow63 = (1.0f - (fConst12 * fSlow61));
		float 	fSlow64 = (fSlow63 / fSlow62);
		float 	fSlow65 = sqrtf(max((float)0, ((faustpower<2>(fSlow63) / faustpower<2>(fSlow62)) - 1.0f)));
		float 	fSlow66 = (fSlow59 * ((1.0f + fSlow65) - fSlow64));
		float 	fSlow67 = (fSlow64 - fSlow65);
		float 	fSlow68 = expf((fConst55 / fSlow11));
		float 	fSlow69 = ((expf((fConst56 / fSlow11)) / fSlow68) - 1);
		float 	fSlow70 = faustpower<2>(fSlow68);
		float 	fSlow71 = (1.0f - fSlow70);
		float 	fSlow72 = (1.0f - (fConst12 * fSlow70));
		float 	fSlow73 = (fSlow72 / fSlow71);
		float 	fSlow74 = sqrtf(max((float)0, ((faustpower<2>(fSlow72) / faustpower<2>(fSlow71)) - 1.0f)));
		float 	fSlow75 = (fSlow68 * ((1.0f + fSlow74) - fSlow73));
		float 	fSlow76 = (fSlow73 - fSlow74);
		float 	fSlow77 = expf((fConst62 / fSlow11));
		float 	fSlow78 = ((expf((fConst63 / fSlow11)) / fSlow77) - 1);
		float 	fSlow79 = faustpower<2>(fSlow77);
		float 	fSlow80 = (1.0f - fSlow79);
		float 	fSlow81 = (1.0f - (fConst12 * fSlow79));
		float 	fSlow82 = (fSlow81 / fSlow80);
		float 	fSlow83 = sqrtf(max((float)0, ((faustpower<2>(fSlow81) / faustpower<2>(fSlow80)) - 1.0f)));
		float 	fSlow84 = (fSlow77 * ((1.0f + fSlow83) - fSlow82));
		float 	fSlow85 = (fSlow82 - fSlow83);
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			fRec0[0] = ((0.999f * fRec0[1]) + fSlow0);
			float fTemp0 = (1 - fRec0[0]);
			iRec3[0] = (12345 + (1103515245 * iRec3[1]));
			fRec2[0] = ((0.9992f * fRec2[1]) + (0.0008000000000000229f * (1 + (2.3283064376228985e-10f * iRec3[0]))));
			float fTemp1 = fRec1[(IOTA-int((1 + int((int((fSlow2 * fRec2[0])) & 4095)))))&8191];
			fVec0[0] = (fSlow3 * fTemp1);
			iRec4[0] = (iSlow5 & (iRec4[1] | (fRec5[1] >= 1)));
			int iTemp2 = (fRec5[1] > 0);
			int iTemp3 = (iSlow6 & iTemp2);
			fRec5[0] = (((fConst3 * (((iRec4[1] == 0) & iSlow5) & (fRec5[1] < 1))) + (fRec5[1] * ((1 - (fConst2 * (iRec4[1] & iTemp2))) - (fConst1 * iTemp3)))) * ((iTemp3 == 0) | (fRec5[1] >= 1e-06f)));
			fRec1[IOTA&8191] = (((fSlow8 * fTemp1) + (fSlow7 * (iRec3[0] * fRec5[0]))) - (0.009900990099009901f * fVec0[1]));
			float fTemp4 = fRec1[(IOTA-0)&8191];
			fRec17[0] = ((fConst7 * fRec17[1]) + (fConst6 * (fRec10[1] + fRec10[2])));
			fRec16[0] = ((fSlow20 * fRec16[1]) + (fSlow19 * (fRec10[1] + (fSlow13 * fRec17[0]))));
			fVec1[IOTA&8191] = (1e-20f + (0.35355339059327373f * fRec16[0]));
			fVec2[IOTA&4095] = (fSlow10 * (fTemp4 * fRec0[0]));
			float fTemp5 = (0.3f * fVec2[(IOTA-iConst15)&4095]);
			float fTemp6 = ((fTemp5 + fVec1[(IOTA-iConst14)&8191]) - (0.6f * fRec14[1]));
			fVec3[IOTA&2047] = fTemp6;
			fRec14[0] = fVec3[(IOTA-iConst16)&2047];
			float 	fRec15 = (0.6f * fVec3[IOTA&2047]);
			fRec21[0] = ((fConst7 * fRec21[1]) + (fConst6 * (fRec6[1] + fRec6[2])));
			fRec20[0] = ((fSlow29 * fRec20[1]) + (fSlow28 * (fRec6[1] + (fSlow22 * fRec21[0]))));
			fVec4[IOTA&8191] = (1e-20f + (0.35355339059327373f * fRec20[0]));
			float fTemp7 = ((fVec4[(IOTA-iConst22)&8191] + fTemp5) - (0.6f * fRec18[1]));
			fVec5[IOTA&1023] = fTemp7;
			fRec18[0] = fVec5[(IOTA-iConst23)&1023];
			float 	fRec19 = (0.6f * fVec5[IOTA&1023]);
			float fTemp8 = (fRec19 + fRec15);
			fRec25[0] = ((fConst7 * fRec25[1]) + (fConst6 * (fRec8[1] + fRec8[2])));
			fRec24[0] = ((fSlow38 * fRec24[1]) + (fSlow37 * (fRec8[1] + (fSlow31 * fRec25[0]))));
			fVec6[IOTA&8191] = (1e-20f + (0.35355339059327373f * fRec24[0]));
			float fTemp9 = (fVec6[(IOTA-iConst29)&8191] - (fTemp5 + (0.6f * fRec22[1])));
			fVec7[IOTA&2047] = fTemp9;
			fRec22[0] = fVec7[(IOTA-iConst30)&2047];
			float 	fRec23 = (0.6f * fVec7[IOTA&2047]);
			fRec29[0] = ((fConst7 * fRec29[1]) + (fConst6 * (fRec12[1] + fRec12[2])));
			fRec28[0] = ((fSlow47 * fRec28[1]) + (fSlow46 * (fRec12[1] + (fSlow40 * fRec29[0]))));
			fVec8[IOTA&8191] = (1e-20f + (0.35355339059327373f * fRec28[0]));
			float fTemp10 = (fVec8[(IOTA-iConst36)&8191] - (fTemp5 + (0.6f * fRec26[1])));
			fVec9[IOTA&1023] = fTemp10;
			fRec26[0] = fVec9[(IOTA-iConst37)&1023];
			float 	fRec27 = (0.6f * fVec9[IOTA&1023]);
			float fTemp11 = (fRec27 + (fRec23 + fTemp8));
			fRec33[0] = ((fConst7 * fRec33[1]) + (fConst6 * (fRec7[1] + fRec7[2])));
			fRec32[0] = ((fSlow56 * fRec32[1]) + (fSlow55 * (fRec7[1] + (fSlow49 * fRec33[0]))));
			fVec10[IOTA&16383] = (1e-20f + (0.35355339059327373f * fRec32[0]));
			float fTemp12 = fRec1[(IOTA-iSlow57)&8191];
			fVec11[IOTA&4095] = (fSlow58 * (fRec0[0] * fTemp12));
			float fTemp13 = (0.3f * fVec11[(IOTA-iConst15)&4095]);
			float fTemp14 = (fTemp13 + ((0.6f * fRec30[1]) + fVec10[(IOTA-iConst43)&16383]));
			fVec12[IOTA&2047] = fTemp14;
			fRec30[0] = fVec12[(IOTA-iConst45)&2047];
			float 	fRec31 = (0 - (0.6f * fVec12[IOTA&2047]));
			fRec37[0] = ((fConst7 * fRec37[1]) + (fConst6 * (fRec11[1] + fRec11[2])));
			fRec36[0] = ((fSlow67 * fRec36[1]) + (fSlow66 * (fRec11[1] + (fSlow60 * fRec37[0]))));
			fVec13[IOTA&8191] = (1e-20f + (0.35355339059327373f * fRec36[0]));
			float fTemp15 = (fVec13[(IOTA-iConst51)&8191] + (fTemp13 + (0.6f * fRec34[1])));
			fVec14[IOTA&2047] = fTemp15;
			fRec34[0] = fVec14[(IOTA-iConst52)&2047];
			float 	fRec35 = (0 - (0.6f * fVec14[IOTA&2047]));
			fRec41[0] = ((fConst7 * fRec41[1]) + (fConst6 * (fRec9[1] + fRec9[2])));
			fRec40[0] = ((fSlow76 * fRec40[1]) + (fSlow75 * (fRec9[1] + (fSlow69 * fRec41[0]))));
			fVec15[IOTA&16383] = (1e-20f + (0.35355339059327373f * fRec40[0]));
			float fTemp16 = (((0.6f * fRec38[1]) + fVec15[(IOTA-iConst58)&16383]) - fTemp13);
			fVec16[IOTA&2047] = fTemp16;
			fRec38[0] = fVec16[(IOTA-iConst59)&2047];
			float 	fRec39 = (0 - (0.6f * fVec16[IOTA&2047]));
			fRec45[0] = ((fConst7 * fRec45[1]) + (fConst6 * (fRec13[1] + fRec13[2])));
			fRec44[0] = ((fSlow85 * fRec44[1]) + (fSlow84 * (fRec13[1] + (fSlow78 * fRec45[0]))));
			fVec17[IOTA&16383] = (1e-20f + (0.35355339059327373f * fRec44[0]));
			float fTemp17 = (((0.6f * fRec42[1]) + fVec17[(IOTA-iConst65)&16383]) - fTemp13);
			fVec18[IOTA&1023] = fTemp17;
			fRec42[0] = fVec18[(IOTA-iConst66)&1023];
			float 	fRec43 = (0 - (0.6f * fVec18[IOTA&1023]));
			fRec6[0] = (fRec42[1] + (fRec38[1] + (fRec34[1] + (fRec30[1] + (fRec26[1] + (fRec22[1] + (fRec14[1] + (fRec18[1] + (fRec43 + (fRec39 + (fRec35 + (fRec31 + fTemp11))))))))))));
			fRec7[0] = (0 - ((fRec42[1] + (fRec38[1] + (fRec34[1] + (fRec30[1] + (fRec43 + (fRec39 + (fRec31 + fRec35))))))) - (fRec26[1] + (fRec22[1] + (fRec14[1] + (fRec18[1] + fTemp11))))));
			float fTemp18 = (fRec23 + fRec27);
			fRec8[0] = (0 - ((fRec42[1] + (fRec38[1] + (fRec26[1] + (fRec22[1] + (fRec43 + (fRec39 + fTemp18)))))) - (fRec34[1] + (fRec30[1] + (fRec14[1] + (fRec18[1] + (fRec35 + (fRec31 + fTemp8))))))));
			fRec9[0] = (0 - ((fRec34[1] + (fRec30[1] + (fRec26[1] + (fRec22[1] + (fRec35 + (fRec31 + fTemp18)))))) - (fRec42[1] + (fRec38[1] + (fRec14[1] + (fRec18[1] + (fRec43 + (fRec39 + fTemp8))))))));
			float fTemp19 = (fRec19 + fRec23);
			float fTemp20 = (fRec15 + fRec27);
			fRec10[0] = (0 - ((fRec42[1] + (fRec34[1] + (fRec26[1] + (fRec14[1] + (fRec43 + (fRec35 + fTemp20)))))) - (fRec38[1] + (fRec30[1] + (fRec22[1] + (fRec18[1] + (fRec39 + (fRec31 + fTemp19))))))));
			fRec11[0] = (0 - ((fRec38[1] + (fRec30[1] + (fRec26[1] + (fRec14[1] + (fRec39 + (fRec31 + fTemp20)))))) - (fRec42[1] + (fRec34[1] + (fRec22[1] + (fRec18[1] + (fRec43 + (fRec35 + fTemp19))))))));
			float fTemp21 = (fRec19 + fRec27);
			float fTemp22 = (fRec15 + fRec23);
			fRec12[0] = (0 - ((fRec38[1] + (fRec34[1] + (fRec22[1] + (fRec14[1] + (fRec39 + (fRec35 + fTemp22)))))) - (fRec42[1] + (fRec30[1] + (fRec26[1] + (fRec18[1] + (fRec43 + (fRec31 + fTemp21))))))));
			fRec13[0] = (0 - ((fRec42[1] + (fRec30[1] + (fRec22[1] + (fRec14[1] + (fRec43 + (fRec31 + fTemp22)))))) - (fRec38[1] + (fRec34[1] + (fRec26[1] + (fRec18[1] + (fRec39 + (fRec35 + fTemp21))))))));
			output0[i] = (FAUSTFLOAT)((0.37f * (fRec7[0] + fRec8[0])) + (fSlow10 * (fTemp4 * fTemp0)));
			output1[i] = (FAUSTFLOAT)((0.37f * (fRec7[0] - fRec8[0])) + (fSlow58 * (fTemp0 * fTemp12)));
			// post processing
			fRec13[2] = fRec13[1]; fRec13[1] = fRec13[0];
			fRec12[2] = fRec12[1]; fRec12[1] = fRec12[0];
			fRec11[2] = fRec11[1]; fRec11[1] = fRec11[0];
			fRec10[2] = fRec10[1]; fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1]; fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1]; fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1]; fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
			fRec42[1] = fRec42[0];
			fRec44[1] = fRec44[0];
			fRec45[1] = fRec45[0];
			fRec38[1] = fRec38[0];
			fRec40[1] = fRec40[0];
			fRec41[1] = fRec41[0];
			fRec34[1] = fRec34[0];
			fRec36[1] = fRec36[0];
			fRec37[1] = fRec37[0];
			fRec30[1] = fRec30[0];
			fRec32[1] = fRec32[0];
			fRec33[1] = fRec33[0];
			fRec26[1] = fRec26[0];
			fRec28[1] = fRec28[0];
			fRec29[1] = fRec29[0];
			fRec22[1] = fRec22[0];
			fRec24[1] = fRec24[0];
			fRec25[1] = fRec25[0];
			fRec18[1] = fRec18[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			fRec14[1] = fRec14[0];
			fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			IOTA = IOTA+1;
			fRec5[1] = fRec5[0];
			iRec4[1] = iRec4[0];
			fVec0[1] = fVec0[0];
			fRec2[1] = fRec2[0];
			iRec3[1] = iRec3[0];
			fRec0[1] = fRec0[0];
		}
	}
};


