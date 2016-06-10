//-----------------------------------------------------
// name: "FourSourcesToOcto"
// version: "1.0"
// author: "CICM"
// license: "BSD"
// copyright: "(c)CICM 2013"
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
	float 	fConst0;
	FAUSTFLOAT 	fslider0;
	float 	fConst1;
	float 	fRec0[2];
	FAUSTFLOAT 	fslider1;
	float 	fRec1[2];
	FAUSTFLOAT 	fslider2;
	float 	fRec2[2];
	FAUSTFLOAT 	fslider3;
	float 	fRec3[2];
	FAUSTFLOAT 	fslider4;
	float 	fRec4[2];
	FAUSTFLOAT 	fslider5;
	float 	fRec5[2];
	FAUSTFLOAT 	fslider6;
	float 	fRec6[2];
	FAUSTFLOAT 	fslider7;
	float 	fRec7[2];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "FourSourcesToOcto");
		m->declare("version", "1.0");
		m->declare("author", "CICM");
		m->declare("license", "BSD");
		m->declare("copyright", "(c)CICM 2013");
		m->declare("hoa.lib/name", "HOA");
		m->declare("hoa.lib/title", "High Order Ambisonics library");
		m->declare("hoa.lib/author", "Pierre Guillot");
		m->declare("hoa.lib/copyright", "2012-2013 Guillot, Paris, Colafrancesco, CICM labex art H2H, U. Paris 8");
		m->declare("math.lib/name", "Math Library");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/version", "1.0");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("filter.lib/copyright", "Julius O. Smith III");
		m->declare("filter.lib/version", "1.29");
		m->declare("filter.lib/license", "STK-4.3");
		m->declare("filter.lib/reference", "https://ccrma.stanford.edu/~jos/filters/");
		m->declare("music.lib/name", "Music Library");
		m->declare("music.lib/author", "GRAME");
		m->declare("music.lib/copyright", "GRAME");
		m->declare("music.lib/version", "1.0");
		m->declare("music.lib/license", "LGPL with exception");
		m->declare("oscillator.lib/name", "Faust Oscillator Library");
		m->declare("oscillator.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("oscillator.lib/copyright", "Julius O. Smith III");
		m->declare("oscillator.lib/version", "1.11");
		m->declare("oscillator.lib/license", "STK-4.3");
	}

	virtual int getNumInputs() 	{ return 4; }
	virtual int getNumOutputs() 	{ return 8; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = expf((0 - (5e+01f / float(min(192000, max(1, fSamplingFreq))))));
		fslider0 = 1.0f;
		fConst1 = (1.0f - fConst0);
		for (int i=0; i<2; i++) fRec0[i] = 0;
		fslider1 = 62831.0f;
		for (int i=0; i<2; i++) fRec1[i] = 0;
		fslider2 = 1.0f;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		fslider3 = 62831.0f;
		for (int i=0; i<2; i++) fRec3[i] = 0;
		fslider4 = 1.0f;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		fslider5 = 62831.0f;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		fslider6 = 1.0f;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		fslider7 = 62831.0f;
		for (int i=0; i<2; i++) fRec7[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("0x00");
		interface->addHorizontalSlider("Angle1", &fslider7, 62831.0f, -6.28318530717959f, 6.28318530717959f, 0.001f);
		interface->addHorizontalSlider("Angle2", &fslider5, 62831.0f, -6.28318530717959f, 6.28318530717959f, 0.001f);
		interface->addHorizontalSlider("Angle3", &fslider3, 62831.0f, -6.28318530717959f, 6.28318530717959f, 0.001f);
		interface->addHorizontalSlider("Angle4", &fslider1, 62831.0f, -6.28318530717959f, 6.28318530717959f, 0.001f);
		interface->addHorizontalSlider("Radius1", &fslider6, 1.0f, 0.0f, 5.0f, 0.001f);
		interface->addHorizontalSlider("Radius2", &fslider4, 1.0f, 0.0f, 5.0f, 0.001f);
		interface->addHorizontalSlider("Radius3", &fslider2, 1.0f, 0.0f, 5.0f, 0.001f);
		interface->addHorizontalSlider("Radius4", &fslider0, 1.0f, 0.0f, 5.0f, 0.001f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (fConst1 * float(fslider0));
		float 	fSlow1 = (fConst1 * float(fslider1));
		float 	fSlow2 = (fConst1 * float(fslider2));
		float 	fSlow3 = (fConst1 * float(fslider3));
		float 	fSlow4 = (fConst1 * float(fslider4));
		float 	fSlow5 = (fConst1 * float(fslider5));
		float 	fSlow6 = (fConst1 * float(fslider6));
		float 	fSlow7 = (fConst1 * float(fslider7));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* input1 = input[1];
		FAUSTFLOAT* input2 = input[2];
		FAUSTFLOAT* input3 = input[3];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		FAUSTFLOAT* output2 = output[2];
		FAUSTFLOAT* output3 = output[3];
		FAUSTFLOAT* output4 = output[4];
		FAUSTFLOAT* output5 = output[5];
		FAUSTFLOAT* output6 = output[6];
		FAUSTFLOAT* output7 = output[7];
		for (int i=0; i<count; i++) {
			fRec0[0] = (fSlow0 + (fConst0 * fRec0[1]));
			int iTemp0 = (fRec0[0] > 1);
			int iTemp1 = (fRec0[0] < 1);
			float fTemp2 = (iTemp1 + (faustpower<2>(fRec0[0]) * iTemp0));
			float fTemp3 = (iTemp0 + (fRec0[0] * iTemp1));
			float fTemp4 = (1.3862943611198906f * fTemp3);
			float fTemp5 = (fTemp4 - 1.0986122886681098f);
			float fTemp6 = (3.4760594967822085f * fTemp5);
			float fTemp7 = ((3.4760594967822085f * ((fTemp5 * (fTemp6 > 0)) * (fTemp6 <= 1))) + (fTemp6 > 1));
			float fTemp8 = (1 + (1.3862943611198906f * (0 - (fTemp3 - 1))));
			fRec1[0] = (fSlow1 + (fConst0 * fRec1[1]));
			float fTemp9 = (3 * fRec1[0]);
			float fTemp10 = (float)input3[i];
			fRec2[0] = (fSlow2 + (fConst0 * fRec2[1]));
			int iTemp11 = (fRec2[0] > 1);
			int iTemp12 = (fRec2[0] < 1);
			float fTemp13 = (iTemp12 + (faustpower<2>(fRec2[0]) * iTemp11));
			float fTemp14 = (iTemp11 + (fRec2[0] * iTemp12));
			float fTemp15 = (1.3862943611198906f * fTemp14);
			float fTemp16 = (fTemp15 - 1.0986122886681098f);
			float fTemp17 = (3.4760594967822085f * fTemp16);
			float fTemp18 = ((3.4760594967822085f * ((fTemp16 * (fTemp17 > 0)) * (fTemp17 <= 1))) + (fTemp17 > 1));
			float fTemp19 = (1 + (1.3862943611198906f * (0 - (fTemp14 - 1))));
			fRec3[0] = (fSlow3 + (fConst0 * fRec3[1]));
			float fTemp20 = (3 * fRec3[0]);
			float fTemp21 = (float)input2[i];
			fRec4[0] = (fSlow4 + (fConst0 * fRec4[1]));
			int iTemp22 = (fRec4[0] > 1);
			int iTemp23 = (fRec4[0] < 1);
			float fTemp24 = (iTemp23 + (faustpower<2>(fRec4[0]) * iTemp22));
			float fTemp25 = (iTemp22 + (fRec4[0] * iTemp23));
			float fTemp26 = (1.3862943611198906f * fTemp25);
			float fTemp27 = (fTemp26 - 1.0986122886681098f);
			float fTemp28 = (3.4760594967822085f * fTemp27);
			float fTemp29 = ((3.4760594967822085f * ((fTemp27 * (fTemp28 > 0)) * (fTemp28 <= 1))) + (fTemp28 > 1));
			float fTemp30 = (1 + (1.3862943611198906f * (0 - (fTemp25 - 1))));
			fRec5[0] = (fSlow5 + (fConst0 * fRec5[1]));
			float fTemp31 = (3 * fRec5[0]);
			float fTemp32 = (float)input1[i];
			fRec6[0] = (fSlow6 + (fConst0 * fRec6[1]));
			int iTemp33 = (fRec6[0] > 1);
			int iTemp34 = (fRec6[0] < 1);
			float fTemp35 = (iTemp34 + (faustpower<2>(fRec6[0]) * iTemp33));
			float fTemp36 = (iTemp33 + (fRec6[0] * iTemp34));
			float fTemp37 = (1.3862943611198906f * fTemp36);
			float fTemp38 = (fTemp37 - 1.0986122886681098f);
			float fTemp39 = (3.4760594967822085f * fTemp38);
			float fTemp40 = ((3.4760594967822085f * ((fTemp38 * (fTemp39 > 0)) * (fTemp39 <= 1))) + (fTemp39 > 1));
			float fTemp41 = (1 + (1.3862943611198906f * (0 - (fTemp36 - 1))));
			fRec7[0] = (fSlow7 + (fConst0 * fRec7[1]));
			float fTemp42 = (3 * fRec7[0]);
			float fTemp43 = (float)input0[i];
			float fTemp44 = (((((((fTemp43 * cosf(fTemp42)) * fTemp41) * fTemp40) / fTemp35) + ((((fTemp32 * cosf(fTemp31)) * fTemp30) * fTemp29) / fTemp24)) + ((((fTemp21 * cosf(fTemp20)) * fTemp19) * fTemp18) / fTemp13)) + ((((fTemp10 * cosf(fTemp9)) * fTemp8) * fTemp7) / fTemp2));
			float fTemp45 = (0.014285714285714285f * fTemp44);
			float fTemp46 = (2 * fRec1[0]);
			float fTemp47 = (fTemp4 - 0.6931471805599453f);
			float fTemp48 = (2.466303462376431f * fTemp47);
			float fTemp49 = ((2.466303462376431f * ((fTemp47 * (fTemp48 > 0)) * (fTemp48 <= 1))) + (fTemp48 > 1));
			float fTemp50 = (fTemp10 * fTemp8);
			float fTemp51 = (2 * fRec3[0]);
			float fTemp52 = (fTemp15 - 0.6931471805599453f);
			float fTemp53 = (2.466303462376431f * fTemp52);
			float fTemp54 = ((2.466303462376431f * ((fTemp52 * (fTemp53 > 0)) * (fTemp53 <= 1))) + (fTemp53 > 1));
			float fTemp55 = (fTemp21 * fTemp19);
			float fTemp56 = (2 * fRec5[0]);
			float fTemp57 = (fTemp26 - 0.6931471805599453f);
			float fTemp58 = (2.466303462376431f * fTemp57);
			float fTemp59 = ((2.466303462376431f * ((fTemp57 * (fTemp58 > 0)) * (fTemp58 <= 1))) + (fTemp58 > 1));
			float fTemp60 = (fTemp32 * fTemp30);
			float fTemp61 = (2 * fRec7[0]);
			float fTemp62 = (fTemp37 - 0.6931471805599453f);
			float fTemp63 = (2.466303462376431f * fTemp62);
			float fTemp64 = ((2.466303462376431f * ((fTemp62 * (fTemp63 > 0)) * (fTemp63 <= 1))) + (fTemp63 > 1));
			float fTemp65 = (fTemp43 * fTemp41);
			float fTemp66 = ((((((fTemp65 * fTemp64) * cosf(fTemp61)) / fTemp35) + (((fTemp60 * fTemp59) * cosf(fTemp56)) / fTemp24)) + (((fTemp55 * fTemp54) * cosf(fTemp51)) / fTemp13)) + (((fTemp50 * fTemp49) * cosf(fTemp46)) / fTemp2));
			float fTemp67 = (0.0857142857142857f * fTemp66);
			float fTemp68 = (2.0f * fTemp3);
			float fTemp69 = ((2.0f * ((fTemp3 * (fTemp68 > 0)) * (fTemp68 <= 1))) + (fTemp68 > 1));
			float fTemp70 = (2.0f * fTemp14);
			float fTemp71 = ((2.0f * ((fTemp14 * (fTemp70 > 0)) * (fTemp70 <= 1))) + (fTemp70 > 1));
			float fTemp72 = (2.0f * fTemp25);
			float fTemp73 = ((2.0f * ((fTemp25 * (fTemp72 > 0)) * (fTemp72 <= 1))) + (fTemp72 > 1));
			float fTemp74 = (2.0f * fTemp36);
			float fTemp75 = ((2.0f * ((fTemp36 * (fTemp74 > 0)) * (fTemp74 <= 1))) + (fTemp74 > 1));
			float fTemp76 = ((((((fTemp65 * fTemp75) * cosf(fRec7[0])) / fTemp35) + (((fTemp60 * fTemp73) * cosf(fRec5[0])) / fTemp24)) + (((fTemp55 * fTemp71) * cosf(fRec3[0])) / fTemp13)) + (((fTemp50 * fTemp69) * cosf(fRec1[0])) / fTemp2));
			float fTemp77 = (0.21428571428571427f * fTemp76);
			float fTemp78 = (0.14285714285714285f * ((((fTemp65 / fTemp35) + (fTemp60 / fTemp24)) + (fTemp55 / fTemp13)) + (fTemp50 / fTemp2)));
			output0[i] = (FAUSTFLOAT)(((fTemp78 + fTemp77) + fTemp67) + fTemp45);
			float fTemp79 = (0.010101525445522105f * fTemp44);
			float fTemp80 = (((((((fTemp43 * sinf(fTemp42)) * fTemp41) * fTemp40) / fTemp35) + ((((fTemp32 * sinf(fTemp31)) * fTemp30) * fTemp29) / fTemp24)) + ((((fTemp21 * sinf(fTemp20)) * fTemp19) * fTemp18) / fTemp13)) + ((((fTemp10 * sinf(fTemp9)) * fTemp8) * fTemp7) / fTemp2));
			float fTemp81 = ((((((fTemp65 * sinf(fTemp61)) * fTemp64) / fTemp35) + (((fTemp60 * sinf(fTemp56)) * fTemp59) / fTemp24)) + (((fTemp55 * sinf(fTemp51)) * fTemp54) / fTemp13)) + (((fTemp50 * sinf(fTemp46)) * fTemp49) / fTemp2));
			float fTemp82 = (0.0857142857142857f * fTemp81);
			float fTemp83 = ((((((fTemp65 * sinf(fRec7[0])) * fTemp75) / fTemp35) + (((fTemp60 * sinf(fRec5[0])) * fTemp73) / fTemp24)) + (((fTemp55 * sinf(fRec3[0])) * fTemp71) / fTemp13)) + (((fTemp50 * sinf(fRec1[0])) * fTemp69) / fTemp2));
			float fTemp84 = (0.15152288168283157f * fTemp83);
			output1[i] = (FAUSTFLOAT)((((((fTemp78 + fTemp84) + (0.15152288168283162f * fTemp76)) + fTemp82) + (5.248486282060085e-18f * fTemp66)) + (0.010101525445522109f * fTemp80)) - fTemp79);
			float fTemp85 = (0.014285714285714285f * fTemp80);
			float fTemp86 = (0.21428571428571427f * fTemp83);
			output2[i] = (FAUSTFLOAT)((((fTemp78 + fTemp86) + (1.3121215705150213e-17f * fTemp76)) + (1.049697256412017e-17f * fTemp81)) - ((fTemp67 + fTemp85) + (2.6242431410300424e-18f * fTemp44)));
			float fTemp87 = (0.15152288168283157f * fTemp76);
			output3[i] = (FAUSTFLOAT)((((fTemp78 + (0.15152288168283162f * fTemp83)) + (0.010101525445522105f * fTemp80)) + (0.01010152544552211f * fTemp44)) - ((fTemp82 + fTemp87) + (1.5745458846180252e-17f * fTemp66)));
			output4[i] = (FAUSTFLOAT)(((fTemp67 + (fTemp78 + (2.6242431410300427e-17f * fTemp83))) + (5.248486282060085e-18f * fTemp80)) - (fTemp45 + (fTemp77 + (2.099394512824034e-17f * fTemp81))));
			output5[i] = (FAUSTFLOAT)((((fTemp78 + fTemp82) + (2.6242431410300424e-17f * fTemp66)) + (0.010101525445522093f * fTemp44)) - ((fTemp84 + (0.15152288168283165f * fTemp76)) + (0.010101525445522121f * fTemp80)));
			output6[i] = (FAUSTFLOAT)(((fTemp85 + (fTemp78 + (3.1490917692360505e-17f * fTemp81))) + (7.872729423090128e-18f * fTemp44)) - (fTemp67 + (fTemp86 + (3.936364711545064e-17f * fTemp76))));
			output7[i] = (FAUSTFLOAT)((fTemp78 + fTemp87) - (fTemp79 + (((fTemp82 + (0.15152288168283165f * fTemp83)) + (3.6739403974420595e-17f * fTemp66)) + (0.01010152544552211f * fTemp80))));
			// post processing
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
		}
	}
};


