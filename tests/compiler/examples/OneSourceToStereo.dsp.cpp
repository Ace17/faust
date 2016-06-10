//-----------------------------------------------------
// name: "OneSourceToStereo"
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
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "OneSourceToStereo");
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

	virtual int getNumInputs() 	{ return 1; }
	virtual int getNumOutputs() 	{ return 2; }
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
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("0x00");
		interface->addHorizontalSlider("Angle", &fslider1, 62831.0f, -6.28318530717959f, 6.28318530717959f, 0.001f);
		interface->addHorizontalSlider("Radius", &fslider0, 1.0f, 0.0f, 5.0f, 0.001f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (fConst1 * float(fslider0));
		float 	fSlow1 = (fConst1 * float(fslider1));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			fRec0[0] = (fSlow0 + (fConst0 * fRec0[1]));
			int iTemp0 = (fRec0[0] > 1);
			int iTemp1 = (fRec0[0] < 1);
			float fTemp2 = (iTemp1 + (faustpower<2>(fRec0[0]) * iTemp0));
			float fTemp3 = (iTemp0 + (fRec0[0] * iTemp1));
			float fTemp4 = (2.0794415416798357f * fTemp3);
			float fTemp5 = (fTemp4 - 1.9459101490553132f);
			float fTemp6 = (7.488875689418624f * fTemp5);
			float fTemp7 = ((7.488875689418624f * ((fTemp5 * (fTemp6 > 0)) * (fTemp6 <= 1))) + (fTemp6 > 1));
			fRec1[0] = (fSlow1 + (fConst0 * fRec1[1]));
			float fTemp8 = (7 * fRec1[0]);
			float fTemp9 = (cosf(fTemp8) * fTemp7);
			float fTemp10 = (sinf(fTemp8) * fTemp7);
			float fTemp11 = (6 * fRec1[0]);
			float fTemp12 = (fTemp4 - 1.791759469228055f);
			float fTemp13 = (6.487159194630884f * fTemp12);
			float fTemp14 = ((6.487159194630884f * ((fTemp12 * (fTemp13 > 0)) * (fTemp13 <= 1))) + (fTemp13 > 1));
			float fTemp15 = (fTemp14 * cosf(fTemp11));
			float fTemp16 = (sinf(fTemp11) * fTemp14);
			float fTemp17 = (5 * fRec1[0]);
			float fTemp18 = (fTemp4 - 1.6094379124341003f);
			float fTemp19 = (5.484814947747076f * fTemp18);
			float fTemp20 = ((5.484814947747076f * ((fTemp18 * (fTemp19 > 0)) * (fTemp19 <= 1))) + (fTemp19 > 1));
			float fTemp21 = (fTemp20 * cosf(fTemp17));
			float fTemp22 = (sinf(fTemp17) * fTemp20);
			float fTemp23 = (4 * fRec1[0]);
			float fTemp24 = (fTemp4 - 1.3862943611198906f);
			float fTemp25 = (4.481420117724551f * fTemp24);
			float fTemp26 = ((4.481420117724551f * ((fTemp24 * (fTemp25 > 0)) * (fTemp25 <= 1))) + (fTemp25 > 1));
			float fTemp27 = (fTemp26 * cosf(fTemp23));
			float fTemp28 = (sinf(fTemp23) * fTemp26);
			float fTemp29 = (0.014141414141414142f * fTemp28);
			float fTemp30 = (3 * fRec1[0]);
			float fTemp31 = (fTemp4 - 1.0986122886681098f);
			float fTemp32 = (3.4760594967822085f * fTemp31);
			float fTemp33 = ((3.4760594967822085f * ((fTemp31 * (fTemp32 > 0)) * (fTemp32 <= 1))) + (fTemp32 > 1));
			float fTemp34 = (fTemp33 * cosf(fTemp30));
			float fTemp35 = (sinf(fTemp30) * fTemp33);
			float fTemp36 = (2 * fRec1[0]);
			float fTemp37 = (fTemp4 - 0.6931471805599453f);
			float fTemp38 = (2.466303462376431f * fTemp37);
			float fTemp39 = ((2.466303462376431f * ((fTemp37 * (fTemp38 > 0)) * (fTemp38 <= 1))) + (fTemp38 > 1));
			float fTemp40 = (fTemp39 * cosf(fTemp36));
			float fTemp41 = (sinf(fTemp36) * fTemp39);
			float fTemp42 = (3.0f * fTemp3);
			float fTemp43 = ((3.0f * ((fTemp3 * (fTemp42 > 0)) * (fTemp42 <= 1))) + (fTemp42 > 1));
			float fTemp44 = (fTemp43 * cosf(fRec1[0]));
			float fTemp45 = (sinf(fRec1[0]) * fTemp43);
			float fTemp46 = ((((((((((((((0.06666666666666667f - (0.04464640044259388f * fTemp45)) + (0.10778594545965009f * fTemp44)) - (0.05499719409228711f * fTemp41)) + (0.05499719409228696f * fTemp40)) - (0.0359286484865501f * fTemp35)) + (0.014882133480864467f * fTemp34)) - fTemp29) - (3.810887590166739e-17f * fTemp27)) - (0.003266240771504547f * fTemp22)) - (0.0013529212255331507f * fTemp21)) - (0.0012395546034863203f * fTemp16)) - (0.0012395546034863392f * fTemp15)) - (0.0010134154163410766f * fTemp10)) - (0.002446601242448649f * fTemp9));
			float fTemp47 = (0.0026481821020520905f * fTemp9);
			float fTemp48 = (0.0035353535353535356f * fTemp21);
			float fTemp49 = (0.03888888888888889f * fTemp34);
			float fTemp50 = (0.11666666666666667f * fTemp44);
			float fTemp51 = (0.07777777777777778f * fTemp40);
			float fTemp52 = (0.014141414141414142f * fTemp27);
			float fTemp53 = (0.0017529949315523716f * fTemp15);
			float fTemp54 = (0.10778594545965012f * fTemp44);
			float fTemp55 = (0.035928648486550044f * fTemp35);
			float fTemp56 = (0.0018725475221778786f * fTemp9);
			float fTemp57 = (0.0018725475221778797f * fTemp10);
			float fTemp58 = (0.07777777777777778f * fTemp41);
			float fTemp59 = (0.0017529949315523716f * fTemp16);
			float fTemp60 = (0.05499719409228705f * fTemp40);
			float fTemp61 = (0.054997194092287024f * fTemp41);
			float fTemp62 = (0.06666666666666667f + (0.10778594545965012f * fTemp45));
			float fTemp63 = (0.0026481821020520905f * fTemp10);
			float fTemp64 = (0.0035353535353535356f * fTemp22);
			float fTemp65 = (0.03888888888888889f * fTemp35);
			float fTemp66 = (0.11666666666666667f * fTemp45);
			float fTemp67 = (0.0024998724587403194f * fTemp22);
			float fTemp68 = (0.08249579113843053f * fTemp45);
			float fTemp69 = (0.0024466012424486424f * fTemp9);
			float fTemp70 = ((((((((((((((0.06666666666666667f + (0.044646400442593805f * fTemp45)) + fTemp54) + fTemp61) + (0.05499719409228703f * fTemp40)) + fTemp55) + (0.014882133480864604f * fTemp34)) + fTemp29) + (8.659118781849972e-19f * fTemp27)) + (0.003266240771504549f * fTemp22)) - (0.0013529212255331455f * fTemp21)) + (0.0012395546034863296f * fTemp16)) - (0.0012395546034863296f * fTemp15)) + (0.0010134154163410928f * fTemp10)) - fTemp69);
			float fTemp71 = (0.7071067811865475f * (((((((0.06666666666666667f + fTemp50) + fTemp51) + fTemp49) + fTemp52) + fTemp48) + fTemp53) + fTemp47));
			float fTemp72 = ((float)input0[i] * (1 + (2.0794415416798357f * (0 - (fTemp3 - 1)))));
			output0[i] = (FAUSTFLOAT)((fTemp72 * (((((((((fTemp71 + (0.9807852804032304f * fTemp70)) + (0.9876883405951377f * ((((((((((((((0.06666666666666667f + fTemp68) + (0.08249579113843054f * fTemp44)) + fTemp58) + (4.762515330017485e-18f * fTemp40)) + (0.027498597046143516f * fTemp35)) - (0.027498597046143512f * fTemp34)) + (1.7318237563699945e-18f * fTemp28)) - fTemp52) - fTemp67) - (0.0024998724587403202f * fTemp21)) - fTemp59) - (3.220199447770718e-19f * fTemp15)) - fTemp57) + fTemp56))) + (0.9238795325112867f * (((((((((((((fTemp62 + (0.04464640044259381f * fTemp44)) + (0.05499719409228703f * fTemp41)) - (0.054997194092287024f * fTemp40)) - (0.014882133480864599f * fTemp35)) - (0.035928648486550044f * fTemp34)) - fTemp29) - (2.5977356345549916e-18f * fTemp27)) - (0.001352921225533148f * fTemp22)) + (0.0032662407715045483f * fTemp21)) + (0.0012395546034863294f * fTemp16)) + (0.00123955460348633f * fTemp15)) + (0.0024466012424486424f * fTemp10)) - (0.0010134154163410928f * fTemp9)))) + (0.8090169943749475f * (((((((fTemp52 + (((((((0.06666666666666667f + fTemp66) + (7.143772995026227e-18f * fTemp44)) + (9.52503066003497e-18f * fTemp41)) - fTemp51) - fTemp65) - (7.143772995026227e-18f * fTemp34)) - (3.463647512739989e-18f * fTemp28))) + fTemp64) + (1.0823898477312466e-18f * fTemp21)) + (6.440398895541436e-19f * fTemp16)) - fTemp53) - fTemp63) - (1.1350807071930908e-18f * fTemp9)))) + (0.6494480483301838f * ((((((((fTemp29 + (((((fTemp62 - (0.0446464004425938f * fTemp44)) - fTemp61) - fTemp60) - (0.014882133480864626f * fTemp35)) + (0.03592864848655004f * fTemp34))) + (4.329559390924986e-18f * fTemp27)) - (0.0013529212255331457f * fTemp22)) - (0.003266240771504549f * fTemp21)) - (0.0012395546034863314f * fTemp16)) + (0.001239554603486328f * fTemp15)) + (0.0024466012424486415f * fTemp10)) + (0.0010134154163410948f * fTemp9)))) + (0.45399049973954686f * ((((fTemp59 + ((((((((((0.06666666666666667f + (0.08249579113843054f * fTemp45)) - (0.08249579113843053f * fTemp44)) - fTemp58) - (1.4287545990052454e-17f * fTemp40)) + (0.02749859704614351f * fTemp35)) + (0.027498597046143526f * fTemp34)) + (5.195471269109983e-18f * fTemp28)) - fTemp52) - (0.002499872458740323f * fTemp22)) + (0.0024998724587403163f * fTemp21))) + (9.660598343312154e-19f * fTemp15)) - fTemp57) - fTemp56))) + (0.23344536385590553f * ((((((((((fTemp55 + ((((0.06666666666666667f + (0.044646400442593825f * fTemp45)) - fTemp54) - (0.05499719409228705f * fTemp41)) + (0.05499719409228702f * fTemp40))) - (0.014882133480864609f * fTemp34)) - fTemp29) - (6.061383147294981e-18f * fTemp27)) + (0.0032662407715045483f * fTemp22)) + (0.0013529212255331488f * fTemp21)) - (0.00123955460348633f * fTemp16)) - (0.0012395546034863294f * fTemp15)) + (0.0010134154163410874f * fTemp10)) + (0.002446601242448644f * fTemp9)))) + (1.2246467991473532e-16f * (((fTemp53 + ((((fTemp52 + ((((fTemp51 + (((0.06666666666666667f + (1.4287545990052454e-17f * fTemp45)) - fTemp50) - (1.905006132006994e-17f * fTemp41))) + (1.4287545990052454e-17f * fTemp35)) - fTemp49) - (6.927295025479978e-18f * fTemp28))) + (2.164779695462493e-18f * fTemp22)) - fTemp48) - (1.2880797791082871e-18f * fTemp16))) + (2.2701614143861816e-18f * fTemp10)) - fTemp47))) + (0.19509032201612825f * fTemp46))) / fTemp2);
			output1[i] = (FAUSTFLOAT)((fTemp72 * ((((((((fTemp71 + (0.19509032201612825f * fTemp70)) + (0.2334453638559054f * (fTemp69 + (((((((fTemp29 + (((fTemp60 + (((0.06666666666666667f - (0.04464640044259379f * fTemp45)) - (0.10778594545965013f * fTemp44)) + (0.05499719409228702f * fTemp41))) - (0.03592864848655003f * fTemp35)) - (0.014882133480864633f * fTemp34))) + (7.793206903664976e-18f * fTemp27)) - (0.0032662407715045496f * fTemp22)) + (0.0013529212255331449f * fTemp21)) + (0.0012395546034863318f * fTemp16)) - (0.0012395546034863277f * fTemp15)) - (0.0010134154163410917f * fTemp10))))) + (0.45399049973954675f * ((((((fTemp67 + ((((((fTemp58 + ((0.06666666666666667f - fTemp68) - (0.08249579113843057f * fTemp44))) + (2.3812576650087427e-17f * fTemp40)) - (0.027498597046143554f * fTemp35)) + (0.02749859704614348f * fTemp34)) + (8.659118781849973e-18f * fTemp28)) - fTemp52)) + (0.0024998724587403194f * fTemp21)) - fTemp59) - (4.7240442599823884e-18f * fTemp15)) + (0.0018725475221778828f * fTemp10)) - (0.0018725475221778756f * fTemp9)))) + (0.6494480483301837f * ((((((((((((((0.06666666666666667f - (0.10778594545965009f * fTemp45)) - (0.044646400442593874f * fTemp44)) + (0.0549971940922871f * fTemp41)) - (0.05499719409228697f * fTemp40)) + (0.014882133480864536f * fTemp35)) + (0.035928648486550065f * fTemp34)) - fTemp29) - (3.46452283889274e-17f * fTemp27)) + (0.0013529212255331557f * fTemp22)) - (0.0032662407715045453f * fTemp21)) + (0.001239554603486325f * fTemp16)) + (0.0012395546034863342f * fTemp15)) - (0.0024466012424486467f * fTemp10)) + (0.001013415416341082f * fTemp9)))) + (0.8090169943749475f * ((fTemp63 + (((((fTemp52 + (((fTemp65 + ((((0.06666666666666667f - fTemp66) - (2.143131898507868e-17f * fTemp44)) + (2.857509198010491e-17f * fTemp41)) - fTemp51)) + (2.1431318985078683e-17f * fTemp34)) - (1.0390942538219966e-17f * fTemp28))) - fTemp64) - (9.527218975416847e-18f * fTemp21)) + (1.932119668662431e-18f * fTemp16)) - fTemp53)) - (1.298874267378291e-18f * fTemp9)))) + (0.9238795325112867f * ((((((((fTemp29 + ((((((0.06666666666666667f - (0.1077859454596501f * fTemp45)) + (0.04464640044259383f * fTemp44)) - (0.054997194092287066f * fTemp41)) - (0.054997194092287004f * fTemp40)) + (0.014882133480864578f * fTemp35)) - (0.03592864848655006f * fTemp34))) - (1.3863343312487467e-17f * fTemp27)) + (0.0013529212255331496f * fTemp22)) + (0.0032662407715045474f * fTemp21)) - (0.0012395546034863279f * fTemp16)) + (0.0012395546034863316f * fTemp15)) - (0.0024466012424486476f * fTemp10)) - (0.0010134154163410796f * fTemp9)))) + (0.9876883405951378f * ((((fTemp59 + ((((((((((0.06666666666666667f - (0.08249579113843057f * fTemp45)) + (0.08249579113843052f * fTemp44)) - fTemp58) - (3.3337607310122396e-17f * fTemp40)) - (0.027498597046143526f * fTemp35)) - (0.02749859704614351f * fTemp34)) + (1.2122766294589962e-17f * fTemp28)) - fTemp52) + (0.002499872458740324f * fTemp22)) - (0.0024998724587403146f * fTemp21))) - (8.598049226575266e-19f * fTemp15)) + (0.0018725475221778715f * fTemp10)) + (0.0018725475221778869f * fTemp9)))) + (0.9807852804032304f * fTemp46))) / fTemp2);
			// post processing
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
		}
	}
};


