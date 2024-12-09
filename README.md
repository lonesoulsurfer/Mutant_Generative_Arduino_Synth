# Mutant_Generative_Arduino_Synth
 Meebleeps awesome Mutant Synth in modular format
First and foremost - I need to do a huge shoutout to MeeBleeps who designed this amazing synth. All I'm doing is creating a PCB and front panel of my own and solving a few issues that I encountered - the software and design is all MeeBleeps.

So what is the Mutant Synth? Well it's a generative synth based around a Arduino Nano and a handful of other components and produces a rich soundscape of sounds.

The synth voice is based around 2 saw oscillators that features:

Multiple tuning modes for the 2nd oscillator - off, detune, fifths & octaves up/down
Low pass filter with variable cutoff and resonance
Variable level ducking/sidechain effects
The display is a 8X8 LED matrix which allows you to visually see where each control level is at. This also includes a 16 step generative sequencer that mutates/evolves at defined rate depending on control inputs.

Variable sequence mutation probability & note-density
Sync input & output (Korg Volca compatible)
Note selection
Selectable scale quantization (Major, Minor, Pentatonic, Phrygian (GOA!), Octaves, Fifths)
16-step parameter-lock recording of synth parameters
Retrig (clone) button for different fills
Tap-tempo control
I've designed the PCB and front panel in a modular synth form factor so if you are into modular synths it will fit right into your Eurorack. You can also use it as a stand alone build which runs off a 9V battery.

The Mozzi library used in the script is an older version which isn't a big deal but you do have do do some pre-work before you can load the script to the Arduino
