/*----------------------------------------------------------------------------------------------------------
 * avSource.cpp
 * 
 * Stub for base MutatingSource class 
 * 
  * Source Code Repository:  https://github.com/Meebleeps/MeeBleeps-Freaq-FM-Synth
 * Youtube Channel:         https://www.youtube.com/channel/UC4I1ExnOpH_GjNtm7ZdWeWA
 * 
 * (C) 2021-2022 Meebleeps
*-----------------------------------------------------------------------------------------------------------
*/
#include "avSource.h"

MutatingSource::MutatingSource()
{
  // base constructor;
  for (uint8_t i = 0; i < MAX_SOURCE_PARAMS; i++)
  {
    param[i] = 0;
  }
}

// Virtual base class method implementations (stubs for derived classes to override)
int MutatingSource::noteOn(byte pitch, byte velocity, unsigned int length)
{
  return 0;
}

int MutatingSource::noteOff()
{
  return 0;
}

AudioOutput_t MutatingSource::updateAudio()
{
  return MonoOutput::from8Bit(0);
}

void MutatingSource::updateControl()
{
}

int MutatingSource::mutate()
{
  return 0;
}

void MutatingSource::setGain(byte gain)
{
}

void MutatingSource::setParam(int paramIndex, int newValue)
{
}

int MutatingSource::getParam(int paramIndex)
{
  return 0;
}
