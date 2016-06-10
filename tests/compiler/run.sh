#!/usr/bin/env bash

set -euo pipefail

readonly tmpDir=/tmp/faust-test-$$
readonly binPath=$1
readonly scriptDir=$(dirname $0)

trap "rm -rf $tmpDir" EXIT
mkdir -p $tmpDir

function main
{
  inputList | while read f; do
    testCompilation "$f"
  done
  test -f $binPath/faust
}

function testCompilation
{
  echo -n "Test $1 : "
  $binPath/faust "$1" > $tmpDir/output.cpp

  local expected="$scriptDir/$f.cpp"
  if ! diff -Naurw $expected $tmpDir/output.cpp ; then
    echo "Error"
    return 1
    #mkdir -p $(dirname $expected)
    #cp $tmpDir/output.cpp $expected
  else
    echo "OK"
  fi
}

function inputList
{
  # Bargraph generation is non-deterministic
#  echo "examples/parametric_eq.dsp"
#  echo "examples/graphic_eq.dsp"
#  echo "examples/vcf_wah_pedals.dsp"
#  echo "examples/dbmeter.dsp"
#  echo "examples/vumeter.dsp"
#  echo "examples/cubic_distortion.dsp"
#  echo "examples/mixer.dsp"
#  echo "examples/spectral_level.dsp"
#  echo "examples/virtual_analog_oscillators.dsp"

  echo "examples/freeverb.dsp"
  echo "examples/capture.dsp"
  echo "examples/UITester.dsp"
  echo "examples/bandfilter.dsp"
  echo "examples/LPF.dsp"
  echo "examples/notch.dsp"
  echo "examples/faust-tubes/preamp.dsp"
  echo "examples/noise.dsp"
  echo "examples/volume.dsp"
  echo "examples/lowboost.dsp"
  echo "examples/peakingEQ.dsp"
  echo "examples/panpot.dsp"
  echo "examples/harpe.dsp"
  echo "examples/HPF.dsp"
#  echo "examples/phaser_flanger.dsp"
  echo "examples/multibandfilter.dsp"
  echo "examples/faust-stk/bowed.dsp"
  echo "examples/faust-stk/brass.dsp"
  echo "examples/faust-stk/flute.dsp"
  echo "examples/faust-stk/flutestk.dsp"
  echo "examples/faust-stk/harpsi.dsp"
  echo "examples/faust-stk/saxophony.dsp"
  echo "examples/faust-stk/NLFfm.dsp"
  echo "examples/faust-stk/clarinet.dsp"
  echo "examples/faust-stk/sitar.dsp"
  echo "examples/faust-stk/tunedBar.dsp"
  echo "examples/faust-stk/blowHole.dsp"
  echo "examples/faust-stk/glassHarmonica.dsp"
  echo "examples/faust-stk/uniBar.dsp"
  echo "examples/faust-stk/tibetanBowl.dsp"
  echo "examples/faust-stk/modalBar.dsp"
  echo "examples/faust-stk/voiceForm.dsp"
  echo "examples/faust-stk/NLFeks.dsp"
  echo "examples/faust-stk/piano.dsp"
  echo "examples/faust-stk/bass.dsp"
  echo "examples/faust-stk/blowBottle.dsp"
  echo "examples/matrix.dsp"
  echo "examples/lowShelf.dsp"
  echo "examples/echo.dsp"
  echo "examples/switcher.dsp"
  echo "examples/tester.dsp"
  echo "examples/reverb_designer.dsp"
  echo "examples/zita_rev1.dsp"
  echo "examples/APF.dsp"
  echo "examples/noisemetadata.dsp"
  echo "examples/lowcut.dsp"
  echo "examples/tester2.dsp"
  echo "examples/osc.dsp"
  echo "examples/BPF.dsp"
  echo "examples/OneSourceToStereo.dsp"
  echo "examples/rewriting/mesh.dsp"
#  echo "examples/rewriting/fold.dsp"
  echo "examples/rewriting/sum.dsp"
  echo "examples/rewriting/serial.dsp"
  echo "examples/rewriting/fact.dsp"
  echo "examples/stereoecho.dsp"
  echo "examples/tapiir.dsp"
  echo "examples/spat.dsp"
  echo "examples/osci.dsp"
  echo "examples/pitch_shifter.dsp"
#  echo "examples/gate_compressor.dsp"
  echo "examples/FourSourcesToOcto.dsp"
  echo "examples/highShelf.dsp"
  echo "examples/quadecho.dsp"
  echo "examples/karplus32.dsp"
  echo "examples/smoothdelay.dsp"
  echo "examples/lfboost.dsp"
  echo "examples/peakNotch.dsp"
  echo "examples/karplus.dsp"
  echo "examples/reverb_tester.dsp"
}

main "$@"

