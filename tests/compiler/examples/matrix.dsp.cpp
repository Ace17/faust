//-----------------------------------------------------
// name: "matrix"
// version: "1.0"
// author: "Grame"
// license: "BSD"
// copyright: "(c)GRAME 2006"
//
// Code generated with Faust 0.9.70 (http://faust.grame.fr)
//-----------------------------------------------------
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  

typedef long double quad;
/* link with  */

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
  private:
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT 	fslider3;
	FAUSTFLOAT 	fslider4;
	FAUSTFLOAT 	fslider5;
	FAUSTFLOAT 	fslider6;
	FAUSTFLOAT 	fslider7;
	FAUSTFLOAT 	fslider8;
	FAUSTFLOAT 	fslider9;
	FAUSTFLOAT 	fslider10;
	FAUSTFLOAT 	fslider11;
	FAUSTFLOAT 	fslider12;
	FAUSTFLOAT 	fslider13;
	FAUSTFLOAT 	fslider14;
	FAUSTFLOAT 	fslider15;
	FAUSTFLOAT 	fslider16;
	FAUSTFLOAT 	fslider17;
	FAUSTFLOAT 	fslider18;
	FAUSTFLOAT 	fslider19;
	FAUSTFLOAT 	fslider20;
	FAUSTFLOAT 	fslider21;
	FAUSTFLOAT 	fslider22;
	FAUSTFLOAT 	fslider23;
	FAUSTFLOAT 	fslider24;
	FAUSTFLOAT 	fslider25;
	FAUSTFLOAT 	fslider26;
	FAUSTFLOAT 	fslider27;
	FAUSTFLOAT 	fslider28;
	FAUSTFLOAT 	fslider29;
	FAUSTFLOAT 	fslider30;
	FAUSTFLOAT 	fslider31;
	FAUSTFLOAT 	fslider32;
	FAUSTFLOAT 	fslider33;
	FAUSTFLOAT 	fslider34;
	FAUSTFLOAT 	fslider35;
	FAUSTFLOAT 	fslider36;
	FAUSTFLOAT 	fslider37;
	FAUSTFLOAT 	fslider38;
	FAUSTFLOAT 	fslider39;
	FAUSTFLOAT 	fslider40;
	FAUSTFLOAT 	fslider41;
	FAUSTFLOAT 	fslider42;
	FAUSTFLOAT 	fslider43;
	FAUSTFLOAT 	fslider44;
	FAUSTFLOAT 	fslider45;
	FAUSTFLOAT 	fslider46;
	FAUSTFLOAT 	fslider47;
	FAUSTFLOAT 	fslider48;
	FAUSTFLOAT 	fslider49;
	FAUSTFLOAT 	fslider50;
	FAUSTFLOAT 	fslider51;
	FAUSTFLOAT 	fslider52;
	FAUSTFLOAT 	fslider53;
	FAUSTFLOAT 	fslider54;
	FAUSTFLOAT 	fslider55;
	FAUSTFLOAT 	fslider56;
	FAUSTFLOAT 	fslider57;
	FAUSTFLOAT 	fslider58;
	FAUSTFLOAT 	fslider59;
	FAUSTFLOAT 	fslider60;
	FAUSTFLOAT 	fslider61;
	FAUSTFLOAT 	fslider62;
	FAUSTFLOAT 	fslider63;
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "matrix");
		m->declare("version", "1.0");
		m->declare("author", "Grame");
		m->declare("license", "BSD");
		m->declare("copyright", "(c)GRAME 2006");
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
	}

	virtual int getNumInputs() 	{ return 8; }
	virtual int getNumOutputs() 	{ return 8; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fslider0 = -1e+01f;
		fslider1 = -1e+01f;
		fslider2 = -1e+01f;
		fslider3 = -1e+01f;
		fslider4 = -1e+01f;
		fslider5 = -1e+01f;
		fslider6 = -1e+01f;
		fslider7 = -1e+01f;
		fslider8 = -1e+01f;
		fslider9 = -1e+01f;
		fslider10 = -1e+01f;
		fslider11 = -1e+01f;
		fslider12 = -1e+01f;
		fslider13 = -1e+01f;
		fslider14 = -1e+01f;
		fslider15 = -1e+01f;
		fslider16 = -1e+01f;
		fslider17 = -1e+01f;
		fslider18 = -1e+01f;
		fslider19 = -1e+01f;
		fslider20 = -1e+01f;
		fslider21 = -1e+01f;
		fslider22 = -1e+01f;
		fslider23 = -1e+01f;
		fslider24 = -1e+01f;
		fslider25 = -1e+01f;
		fslider26 = -1e+01f;
		fslider27 = -1e+01f;
		fslider28 = -1e+01f;
		fslider29 = -1e+01f;
		fslider30 = -1e+01f;
		fslider31 = -1e+01f;
		fslider32 = -1e+01f;
		fslider33 = -1e+01f;
		fslider34 = -1e+01f;
		fslider35 = -1e+01f;
		fslider36 = -1e+01f;
		fslider37 = -1e+01f;
		fslider38 = -1e+01f;
		fslider39 = -1e+01f;
		fslider40 = -1e+01f;
		fslider41 = -1e+01f;
		fslider42 = -1e+01f;
		fslider43 = -1e+01f;
		fslider44 = -1e+01f;
		fslider45 = -1e+01f;
		fslider46 = -1e+01f;
		fslider47 = -1e+01f;
		fslider48 = -1e+01f;
		fslider49 = -1e+01f;
		fslider50 = -1e+01f;
		fslider51 = -1e+01f;
		fslider52 = -1e+01f;
		fslider53 = -1e+01f;
		fslider54 = -1e+01f;
		fslider55 = -1e+01f;
		fslider56 = -1e+01f;
		fslider57 = -1e+01f;
		fslider58 = -1e+01f;
		fslider59 = -1e+01f;
		fslider60 = -1e+01f;
		fslider61 = -1e+01f;
		fslider62 = -1e+01f;
		fslider63 = -1e+01f;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openTabBox("Matrix 8 x 8");
		interface->openHorizontalBox("Output 0");
		interface->addVerticalSlider("Input 0", &fslider7, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 1", &fslider6, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 2", &fslider5, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 3", &fslider4, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 4", &fslider3, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 5", &fslider2, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 6", &fslider1, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 7", &fslider0, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->closeBox();
		interface->openHorizontalBox("Output 1");
		interface->addVerticalSlider("Input 0", &fslider15, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 1", &fslider14, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 2", &fslider13, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 3", &fslider12, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 4", &fslider11, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 5", &fslider10, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 6", &fslider9, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 7", &fslider8, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->closeBox();
		interface->openHorizontalBox("Output 2");
		interface->addVerticalSlider("Input 0", &fslider23, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 1", &fslider22, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 2", &fslider21, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 3", &fslider20, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 4", &fslider19, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 5", &fslider18, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 6", &fslider17, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 7", &fslider16, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->closeBox();
		interface->openHorizontalBox("Output 3");
		interface->addVerticalSlider("Input 0", &fslider31, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 1", &fslider30, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 2", &fslider29, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 3", &fslider28, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 4", &fslider27, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 5", &fslider26, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 6", &fslider25, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 7", &fslider24, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->closeBox();
		interface->openHorizontalBox("Output 4");
		interface->addVerticalSlider("Input 0", &fslider39, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 1", &fslider38, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 2", &fslider37, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 3", &fslider36, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 4", &fslider35, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 5", &fslider34, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 6", &fslider33, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 7", &fslider32, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->closeBox();
		interface->openHorizontalBox("Output 5");
		interface->addVerticalSlider("Input 0", &fslider47, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 1", &fslider46, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 2", &fslider45, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 3", &fslider44, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 4", &fslider43, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 5", &fslider42, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 6", &fslider41, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 7", &fslider40, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->closeBox();
		interface->openHorizontalBox("Output 6");
		interface->addVerticalSlider("Input 0", &fslider55, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 1", &fslider54, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 2", &fslider53, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 3", &fslider52, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 4", &fslider51, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 5", &fslider50, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 6", &fslider49, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 7", &fslider48, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->closeBox();
		interface->openHorizontalBox("Output 7");
		interface->addVerticalSlider("Input 0", &fslider63, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 1", &fslider62, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 2", &fslider61, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 3", &fslider60, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 4", &fslider59, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 5", &fslider58, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 6", &fslider57, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->addVerticalSlider("Input 7", &fslider56, -1e+01f, -96.0f, 4.0f, 0.1f);
		interface->closeBox();
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = powf(10,(0.05f * float(fslider0)));
		float 	fSlow1 = powf(10,(0.05f * float(fslider1)));
		float 	fSlow2 = powf(10,(0.05f * float(fslider2)));
		float 	fSlow3 = powf(10,(0.05f * float(fslider3)));
		float 	fSlow4 = powf(10,(0.05f * float(fslider4)));
		float 	fSlow5 = powf(10,(0.05f * float(fslider5)));
		float 	fSlow6 = powf(10,(0.05f * float(fslider6)));
		float 	fSlow7 = powf(10,(0.05f * float(fslider7)));
		float 	fSlow8 = powf(10,(0.05f * float(fslider8)));
		float 	fSlow9 = powf(10,(0.05f * float(fslider9)));
		float 	fSlow10 = powf(10,(0.05f * float(fslider10)));
		float 	fSlow11 = powf(10,(0.05f * float(fslider11)));
		float 	fSlow12 = powf(10,(0.05f * float(fslider12)));
		float 	fSlow13 = powf(10,(0.05f * float(fslider13)));
		float 	fSlow14 = powf(10,(0.05f * float(fslider14)));
		float 	fSlow15 = powf(10,(0.05f * float(fslider15)));
		float 	fSlow16 = powf(10,(0.05f * float(fslider16)));
		float 	fSlow17 = powf(10,(0.05f * float(fslider17)));
		float 	fSlow18 = powf(10,(0.05f * float(fslider18)));
		float 	fSlow19 = powf(10,(0.05f * float(fslider19)));
		float 	fSlow20 = powf(10,(0.05f * float(fslider20)));
		float 	fSlow21 = powf(10,(0.05f * float(fslider21)));
		float 	fSlow22 = powf(10,(0.05f * float(fslider22)));
		float 	fSlow23 = powf(10,(0.05f * float(fslider23)));
		float 	fSlow24 = powf(10,(0.05f * float(fslider24)));
		float 	fSlow25 = powf(10,(0.05f * float(fslider25)));
		float 	fSlow26 = powf(10,(0.05f * float(fslider26)));
		float 	fSlow27 = powf(10,(0.05f * float(fslider27)));
		float 	fSlow28 = powf(10,(0.05f * float(fslider28)));
		float 	fSlow29 = powf(10,(0.05f * float(fslider29)));
		float 	fSlow30 = powf(10,(0.05f * float(fslider30)));
		float 	fSlow31 = powf(10,(0.05f * float(fslider31)));
		float 	fSlow32 = powf(10,(0.05f * float(fslider32)));
		float 	fSlow33 = powf(10,(0.05f * float(fslider33)));
		float 	fSlow34 = powf(10,(0.05f * float(fslider34)));
		float 	fSlow35 = powf(10,(0.05f * float(fslider35)));
		float 	fSlow36 = powf(10,(0.05f * float(fslider36)));
		float 	fSlow37 = powf(10,(0.05f * float(fslider37)));
		float 	fSlow38 = powf(10,(0.05f * float(fslider38)));
		float 	fSlow39 = powf(10,(0.05f * float(fslider39)));
		float 	fSlow40 = powf(10,(0.05f * float(fslider40)));
		float 	fSlow41 = powf(10,(0.05f * float(fslider41)));
		float 	fSlow42 = powf(10,(0.05f * float(fslider42)));
		float 	fSlow43 = powf(10,(0.05f * float(fslider43)));
		float 	fSlow44 = powf(10,(0.05f * float(fslider44)));
		float 	fSlow45 = powf(10,(0.05f * float(fslider45)));
		float 	fSlow46 = powf(10,(0.05f * float(fslider46)));
		float 	fSlow47 = powf(10,(0.05f * float(fslider47)));
		float 	fSlow48 = powf(10,(0.05f * float(fslider48)));
		float 	fSlow49 = powf(10,(0.05f * float(fslider49)));
		float 	fSlow50 = powf(10,(0.05f * float(fslider50)));
		float 	fSlow51 = powf(10,(0.05f * float(fslider51)));
		float 	fSlow52 = powf(10,(0.05f * float(fslider52)));
		float 	fSlow53 = powf(10,(0.05f * float(fslider53)));
		float 	fSlow54 = powf(10,(0.05f * float(fslider54)));
		float 	fSlow55 = powf(10,(0.05f * float(fslider55)));
		float 	fSlow56 = powf(10,(0.05f * float(fslider56)));
		float 	fSlow57 = powf(10,(0.05f * float(fslider57)));
		float 	fSlow58 = powf(10,(0.05f * float(fslider58)));
		float 	fSlow59 = powf(10,(0.05f * float(fslider59)));
		float 	fSlow60 = powf(10,(0.05f * float(fslider60)));
		float 	fSlow61 = powf(10,(0.05f * float(fslider61)));
		float 	fSlow62 = powf(10,(0.05f * float(fslider62)));
		float 	fSlow63 = powf(10,(0.05f * float(fslider63)));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* input1 = input[1];
		FAUSTFLOAT* input2 = input[2];
		FAUSTFLOAT* input3 = input[3];
		FAUSTFLOAT* input4 = input[4];
		FAUSTFLOAT* input5 = input[5];
		FAUSTFLOAT* input6 = input[6];
		FAUSTFLOAT* input7 = input[7];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		FAUSTFLOAT* output2 = output[2];
		FAUSTFLOAT* output3 = output[3];
		FAUSTFLOAT* output4 = output[4];
		FAUSTFLOAT* output5 = output[5];
		FAUSTFLOAT* output6 = output[6];
		FAUSTFLOAT* output7 = output[7];
		for (int i=0; i<count; i++) {
			float fTemp0 = (float)input7[i];
			float fTemp1 = (float)input6[i];
			float fTemp2 = (float)input5[i];
			float fTemp3 = (float)input4[i];
			float fTemp4 = (float)input3[i];
			float fTemp5 = (float)input2[i];
			float fTemp6 = (float)input1[i];
			float fTemp7 = (float)input0[i];
			output0[i] = (FAUSTFLOAT)((((((((fSlow7 * fTemp7) + (fSlow6 * fTemp6)) + (fSlow5 * fTemp5)) + (fSlow4 * fTemp4)) + (fSlow3 * fTemp3)) + (fSlow2 * fTemp2)) + (fSlow1 * fTemp1)) + (fSlow0 * fTemp0));
			output1[i] = (FAUSTFLOAT)((((((((fSlow15 * fTemp7) + (fSlow14 * fTemp6)) + (fSlow13 * fTemp5)) + (fSlow12 * fTemp4)) + (fSlow11 * fTemp3)) + (fSlow10 * fTemp2)) + (fSlow9 * fTemp1)) + (fSlow8 * fTemp0));
			output2[i] = (FAUSTFLOAT)((((((((fSlow23 * fTemp7) + (fSlow22 * fTemp6)) + (fSlow21 * fTemp5)) + (fSlow20 * fTemp4)) + (fSlow19 * fTemp3)) + (fSlow18 * fTemp2)) + (fSlow17 * fTemp1)) + (fSlow16 * fTemp0));
			output3[i] = (FAUSTFLOAT)((((((((fSlow31 * fTemp7) + (fSlow30 * fTemp6)) + (fSlow29 * fTemp5)) + (fSlow28 * fTemp4)) + (fSlow27 * fTemp3)) + (fSlow26 * fTemp2)) + (fSlow25 * fTemp1)) + (fSlow24 * fTemp0));
			output4[i] = (FAUSTFLOAT)((((((((fSlow39 * fTemp7) + (fSlow38 * fTemp6)) + (fSlow37 * fTemp5)) + (fSlow36 * fTemp4)) + (fSlow35 * fTemp3)) + (fSlow34 * fTemp2)) + (fSlow33 * fTemp1)) + (fSlow32 * fTemp0));
			output5[i] = (FAUSTFLOAT)((((((((fSlow47 * fTemp7) + (fSlow46 * fTemp6)) + (fSlow45 * fTemp5)) + (fSlow44 * fTemp4)) + (fSlow43 * fTemp3)) + (fSlow42 * fTemp2)) + (fSlow41 * fTemp1)) + (fSlow40 * fTemp0));
			output6[i] = (FAUSTFLOAT)((((((((fSlow55 * fTemp7) + (fSlow54 * fTemp6)) + (fSlow53 * fTemp5)) + (fSlow52 * fTemp4)) + (fSlow51 * fTemp3)) + (fSlow50 * fTemp2)) + (fSlow49 * fTemp1)) + (fSlow48 * fTemp0));
			output7[i] = (FAUSTFLOAT)((((((((fSlow63 * fTemp7) + (fSlow62 * fTemp6)) + (fSlow61 * fTemp5)) + (fSlow60 * fTemp4)) + (fSlow59 * fTemp3)) + (fSlow58 * fTemp2)) + (fSlow57 * fTemp1)) + (fSlow56 * fTemp0));
		}
	}
};


