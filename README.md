![image](https://github.com/user-attachments/assets/42a99a8d-a4a7-4d8c-a2f1-79578fdb59c8)

# Mutant_Generative_Arduino_Synth

 Meebleeps awesome Mutant Synth in modular format

First and foremost - I need to do a huge shoutout to MeeBleeps (https://github.com/Meebleeps/MeeBleeps-Mutant-Synth) who designed this amazing synth. I've designed a PCB and front panel to fit modular synths or you could use it as a stand alone synth if you wanted to.  You can power it from 9 to 12 V's

You can find a step by step guide on my Instructables page on how to build your own - https://www.instructables.com/Mutant-Generative-Arduino-Synth/

I have also posted a video on my YouTube page - https://studio.youtube.com/video/L1Gzkz4_xpQ/edit

The main goal with building this module is to create my own 'simple to build' modular synth. I wanted to keep everything as easy as possble with each module built with the following aims:

Can be powered by 9V (and 12V)
Easy to build with minimum components
Use Arduino to keep it simple (plus it helps to keep the components down and everything in tune)
Can fit into any modular synth Eurorck (include the ability to power the module via normal module power sources)
Has to sound great!
Lastly, it should be portable and be powered from a 9V battery

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

The Mozzi library used in the script is an older version which isn't a big deal but you will need to update IDE with an older version of Mozzie (1.1.2).  You can easily do this in IDE but if you are unsure how to do this then check out my Instruacable I published.
![image](https://github.com/user-attachments/assets/2f61441d-f15d-466a-be38-71519ba5a62b)
