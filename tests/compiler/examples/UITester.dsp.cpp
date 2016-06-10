//-----------------------------------------------------
// name: "UI Tester"
// version: "1.0"
// author: "O. Guillerminet"
// license: "BSD"
// copyright: "(c) O. Guillerminet 2012"
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
	FAUSTFLOAT 	fcheckbox0;
	FAUSTFLOAT 	fcheckbox1;
	FAUSTFLOAT 	fentry0;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT 	fslider3;
	FAUSTFLOAT 	fslider4;
	FAUSTFLOAT 	fslider5;
	FAUSTFLOAT 	fslider6;
	FAUSTFLOAT 	fbutton0;
	FAUSTFLOAT 	fslider7;
	FAUSTFLOAT 	fslider8;
	FAUSTFLOAT 	fslider9;
	FAUSTFLOAT 	fslider10;
	FAUSTFLOAT 	fentry1;
	FAUSTFLOAT 	fbargraph0;
	FAUSTFLOAT 	fslider11;
	FAUSTFLOAT 	fslider12;
	FAUSTFLOAT 	fslider13;
	FAUSTFLOAT 	fentry2;
	FAUSTFLOAT 	fbargraph1;
	FAUSTFLOAT 	fslider14;
	FAUSTFLOAT 	fslider15;
	FAUSTFLOAT 	fslider16;
	FAUSTFLOAT 	fentry3;
	FAUSTFLOAT 	fbargraph2;
	FAUSTFLOAT 	fbargraph3;
	FAUSTFLOAT 	fslider17;
	FAUSTFLOAT 	fbutton1;
	FAUSTFLOAT 	fslider18;
	FAUSTFLOAT 	fentry4;
	FAUSTFLOAT 	fbargraph4;
	FAUSTFLOAT 	fbargraph5;
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "UI Tester");
		m->declare("version", "1.0");
		m->declare("author", "O. Guillerminet");
		m->declare("license", "BSD");
		m->declare("copyright", "(c) O. Guillerminet 2012");
	}

	virtual int getNumInputs() 	{ return 6; }
	virtual int getNumOutputs() 	{ return 34; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fcheckbox0 = 0.0;
		fcheckbox1 = 0.0;
		fentry0 = 6e+01f;
		fslider0 = 6e+01f;
		fslider1 = 6e+01f;
		fslider2 = 6e+01f;
		fslider3 = 6e+01f;
		fslider4 = 6e+01f;
		fslider5 = 6e+01f;
		fslider6 = 6e+01f;
		fbutton0 = 0.0;
		fslider7 = 6e+01f;
		fslider8 = 6e+01f;
		fslider9 = 6e+01f;
		fslider10 = 6e+01f;
		fentry1 = 6e+01f;
		fslider11 = 6e+01f;
		fslider12 = 6e+01f;
		fslider13 = 6e+01f;
		fentry2 = 6e+01f;
		fslider14 = 6e+01f;
		fslider15 = 6e+01f;
		fslider16 = 6e+01f;
		fentry3 = 6e+01f;
		fslider17 = 6e+01f;
		fbutton1 = 0.0;
		fslider18 = 6e+01f;
		fentry4 = 6e+01f;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openTabBox("grp 1");
		interface->openHorizontalBox("hmisc");
		interface->addButton("button", &fbutton1);
		interface->addHorizontalBargraph("hbar", &fbargraph5, 0.0f, 127.0f);
		interface->addHorizontalSlider("hslider", &fslider18, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->declare(&fentry4, "unit", "f");
		interface->addNumEntry("num", &fentry4, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->addVerticalBargraph("vbar", &fbargraph4, 0.0f, 127.0f);
		interface->declare(&fslider17, "unit", "f");
		interface->addVerticalSlider("vslider4", &fslider17, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->closeBox();
		interface->openHorizontalBox("knobs");
		interface->declare(&fslider3, "style", "knob");
		interface->addVerticalSlider("knob1", &fslider3, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->declare(&fslider4, "style", "knob");
		interface->addVerticalSlider("knob2", &fslider4, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->declare(&fslider5, "style", "knob");
		interface->addVerticalSlider("knob3", &fslider5, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->closeBox();
		interface->openHorizontalBox("sliders");
		interface->addVerticalSlider("vslider1", &fslider0, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->addVerticalSlider("vslider2", &fslider1, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->addVerticalSlider("vslider3", &fslider2, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->closeBox();
		interface->openVerticalBox("vbox");
		interface->addCheckButton("check1", &fcheckbox0);
		interface->addCheckButton("check2", &fcheckbox1);
		interface->declare(&fentry0, "style", "knob");
		interface->addNumEntry("knob0", &fentry0, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->closeBox();
		interface->openVerticalBox("vmisc");
		interface->addButton("button", &fbutton0);
		interface->addHorizontalBargraph("hbar", &fbargraph3, 0.0f, 127.0f);
		interface->declare(&fslider7, "unit", "Hz");
		interface->addHorizontalSlider("hslider", &fslider7, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->openHorizontalBox("small box 1");
		interface->declare(&fslider10, "style", "knob");
		interface->addVerticalSlider("knob4", &fslider10, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->declare(&fentry1, "unit", "f");
		interface->addNumEntry("num1", &fentry1, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->addVerticalBargraph("vbar1", &fbargraph0, 0.0f, 127.0f);
		interface->declare(&fslider8, "unit", "Hz");
		interface->addVerticalSlider("vslider5", &fslider8, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->declare(&fslider9, "unit", "Hz");
		interface->addVerticalSlider("vslider6", &fslider9, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->closeBox();
		interface->openHorizontalBox("sub box 1");
		interface->openHorizontalBox("small box 2");
		interface->declare(&fslider13, "style", "knob");
		interface->addVerticalSlider("knob5", &fslider13, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->declare(&fentry2, "unit", "f");
		interface->addNumEntry("num2", &fentry2, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->addVerticalBargraph("vbar2", &fbargraph1, 0.0f, 127.0f);
		interface->declare(&fslider11, "unit", "Hz");
		interface->addVerticalSlider("vslider7", &fslider11, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->declare(&fslider12, "unit", "Hz");
		interface->addVerticalSlider("vslider8", &fslider12, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->closeBox();
		interface->openHorizontalBox("small box 3");
		interface->declare(&fslider16, "style", "knob");
		interface->addVerticalSlider("knob6", &fslider16, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->declare(&fentry3, "unit", "f");
		interface->addNumEntry("num3", &fentry3, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->addVerticalBargraph("vbar3", &fbargraph2, 0.0f, 127.0f);
		interface->declare(&fslider15, "unit", "m");
		interface->addVerticalSlider("vslider10", &fslider15, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->declare(&fslider14, "unit", "Hz");
		interface->addVerticalSlider("vslider9", &fslider14, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->closeBox();
		interface->closeBox();
		interface->declare(&fslider6, "unit", "Hz");
		interface->addVerticalSlider("vslider4", &fslider6, 6e+01f, 0.0f, 127.0f, 0.1f);
		interface->closeBox();
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = float(fcheckbox0);
		float 	fSlow1 = float(fcheckbox1);
		float 	fSlow2 = float(fentry0);
		float 	fSlow3 = float(fslider0);
		float 	fSlow4 = float(fslider1);
		float 	fSlow5 = float(fslider2);
		float 	fSlow6 = float(fslider3);
		float 	fSlow7 = float(fslider4);
		float 	fSlow8 = float(fslider5);
		float 	fSlow9 = float(fslider6);
		float 	fSlow10 = float(fbutton0);
		float 	fSlow11 = float(fslider7);
		float 	fSlow12 = float(fslider8);
		float 	fSlow13 = float(fslider9);
		float 	fSlow14 = float(fslider10);
		float 	fSlow15 = float(fentry1);
		float 	fSlow16 = float(fslider11);
		float 	fSlow17 = float(fslider12);
		float 	fSlow18 = float(fslider13);
		float 	fSlow19 = float(fentry2);
		float 	fSlow20 = float(fslider14);
		float 	fSlow21 = float(fslider15);
		float 	fSlow22 = float(fslider16);
		float 	fSlow23 = float(fentry3);
		float 	fSlow24 = float(fslider17);
		float 	fSlow25 = float(fbutton1);
		float 	fSlow26 = float(fslider18);
		float 	fSlow27 = float(fentry4);
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* input1 = input[1];
		FAUSTFLOAT* input2 = input[2];
		FAUSTFLOAT* input3 = input[3];
		FAUSTFLOAT* input4 = input[4];
		FAUSTFLOAT* input5 = input[5];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		FAUSTFLOAT* output2 = output[2];
		FAUSTFLOAT* output3 = output[3];
		FAUSTFLOAT* output4 = output[4];
		FAUSTFLOAT* output5 = output[5];
		FAUSTFLOAT* output6 = output[6];
		FAUSTFLOAT* output7 = output[7];
		FAUSTFLOAT* output8 = output[8];
		FAUSTFLOAT* output9 = output[9];
		FAUSTFLOAT* output10 = output[10];
		FAUSTFLOAT* output11 = output[11];
		FAUSTFLOAT* output12 = output[12];
		FAUSTFLOAT* output13 = output[13];
		FAUSTFLOAT* output14 = output[14];
		FAUSTFLOAT* output15 = output[15];
		FAUSTFLOAT* output16 = output[16];
		FAUSTFLOAT* output17 = output[17];
		FAUSTFLOAT* output18 = output[18];
		FAUSTFLOAT* output19 = output[19];
		FAUSTFLOAT* output20 = output[20];
		FAUSTFLOAT* output21 = output[21];
		FAUSTFLOAT* output22 = output[22];
		FAUSTFLOAT* output23 = output[23];
		FAUSTFLOAT* output24 = output[24];
		FAUSTFLOAT* output25 = output[25];
		FAUSTFLOAT* output26 = output[26];
		FAUSTFLOAT* output27 = output[27];
		FAUSTFLOAT* output28 = output[28];
		FAUSTFLOAT* output29 = output[29];
		FAUSTFLOAT* output30 = output[30];
		FAUSTFLOAT* output31 = output[31];
		FAUSTFLOAT* output32 = output[32];
		FAUSTFLOAT* output33 = output[33];
		for (int i=0; i<count; i++) {
			output0[i] = (FAUSTFLOAT)fSlow0;
			output1[i] = (FAUSTFLOAT)fSlow1;
			output2[i] = (FAUSTFLOAT)fSlow2;
			output3[i] = (FAUSTFLOAT)fSlow3;
			output4[i] = (FAUSTFLOAT)fSlow4;
			output5[i] = (FAUSTFLOAT)fSlow5;
			output6[i] = (FAUSTFLOAT)fSlow6;
			output7[i] = (FAUSTFLOAT)fSlow7;
			output8[i] = (FAUSTFLOAT)fSlow8;
			output9[i] = (FAUSTFLOAT)fSlow9;
			output10[i] = (FAUSTFLOAT)fSlow10;
			output11[i] = (FAUSTFLOAT)fSlow11;
			output12[i] = (FAUSTFLOAT)fSlow12;
			output13[i] = (FAUSTFLOAT)fSlow13;
			output14[i] = (FAUSTFLOAT)fSlow14;
			output15[i] = (FAUSTFLOAT)fSlow15;
			fbargraph0 = (float)input0[i];
			output16[i] = (FAUSTFLOAT)fbargraph0;
			output17[i] = (FAUSTFLOAT)fSlow16;
			output18[i] = (FAUSTFLOAT)fSlow17;
			output19[i] = (FAUSTFLOAT)fSlow18;
			output20[i] = (FAUSTFLOAT)fSlow19;
			fbargraph1 = (float)input1[i];
			output21[i] = (FAUSTFLOAT)fbargraph1;
			output22[i] = (FAUSTFLOAT)fSlow20;
			output23[i] = (FAUSTFLOAT)fSlow21;
			output24[i] = (FAUSTFLOAT)fSlow22;
			output25[i] = (FAUSTFLOAT)fSlow23;
			fbargraph2 = (float)input2[i];
			output26[i] = (FAUSTFLOAT)fbargraph2;
			fbargraph3 = (float)input3[i];
			output27[i] = (FAUSTFLOAT)fbargraph3;
			output28[i] = (FAUSTFLOAT)fSlow24;
			output29[i] = (FAUSTFLOAT)fSlow25;
			output30[i] = (FAUSTFLOAT)fSlow26;
			output31[i] = (FAUSTFLOAT)fSlow27;
			fbargraph4 = (float)input4[i];
			output32[i] = (FAUSTFLOAT)fbargraph4;
			fbargraph5 = (float)input5[i];
			output33[i] = (FAUSTFLOAT)fbargraph5;
		}
	}
};


