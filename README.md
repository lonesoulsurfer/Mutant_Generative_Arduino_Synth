# Mutant: generative Arduino synth for Eurorack

Mutant is a generative synth that uses an Arduino Nano. The synth design and the code are by [Meebleeps](https://github.com/Meebleeps/MeeBleeps-Mutant-Synth). I designed a PCB and a front panel, so that it fits in a Eurorack case. You can also use it as a standalone synth.

![Mutant](https://github.com/user-attachments/assets/42a99a8d-a4a7-4d8c-a2f1-79578fdb59c8)

## Build guide and video

- Step-by-step build guide on Instructables: [Mutant Generative Arduino Synth](https://www.instructables.com/Mutant-Generative-Arduino-Synth/)
- Video on YouTube: [Mutant](https://www.youtube.com/watch?v=L1Gzkz4_xpQ)

## Features

The synth voice has 2 saw oscillators, with:

- Tuning modes for the second oscillator: off, detune, fifths, and octaves up or down
- Low-pass filter with cutoff and resonance controls
- Ducking (sidechain) effect with a level control

An 8 × 8 LED matrix shows the level of each control. The 16-step generative sequencer changes (mutates) at a rate that you set. It has:

- Mutation probability and note-density controls
- Sync input and sync output (compatible with Korg Volca)
- Note selection
- Scale quantization: major, minor, pentatonic, Phrygian, octaves and fifths
- 16-step parameter-lock recording
- A retrigger (clone) button for fills
- Tap tempo

Power: 9 V to 12 V, from a Eurorack power connector or a 9 V supply.

## What you need

### Hardware

- All parts are in the [parts list](Parts%20List/Mutant+-+List+of+Parts.pdf).
- The schematic is [Schematic.png](Schematic.png).
- The Gerber files for the PCB and the front panel are in [Gerber Files](Gerber%20Files/). You can send them to a PCB maker.

### Software

- Arduino IDE
- The **Mozzi** library. The version that you need depends on the sketch. See the next section.

## Select the sketch

There are two sketches in `Mutant_IDE_Code/`. They make the same sounds.

| Sketch | Mozzi version | Use it when |
|--------|---------------|-------------|
| `Mutant_Updated` | Mozzi 2 (the current version) | **Recommended.** Use this sketch. |
| `Mutant_Original` | Mozzi 1.1.2 (old version) | Only if you already use Mozzi 1.1.2 |

## Upload the firmware

1. Download this repository. Click **Code → Download ZIP**, then extract the ZIP file.
2. In the Arduino IDE, open the **Library Manager**.
3. Search for **Mozzi** and install the newest version.
4. Open `Mutant_IDE_Code/Mutant_Updated/Mutant_Updated.ino`.
5. Connect the Arduino Nano to your computer with a USB cable.
6. In the **Tools** menu, set these values:
   - **Board:** Arduino Nano
   - **Processor:** ATmega328P
   - **Port:** the COM port of your Nano
7. Click **Upload**.
8. Wait for the message **Done uploading**.

> **Note:** If the upload fails, set **Processor** to **ATmega328P (Old Bootloader)**, then try again. Many clone Nano boards need this setting.

> **Note:** To use `Mutant_Original`, install Mozzi version **1.1.2** in step 3. In the Library Manager, select **1.1.2** in the version list, then click **Install**.

## How to play

The controls are described in the [Meebleeps Mutant Synth README](https://github.com/Meebleeps/MeeBleeps-Mutant-Synth#controls).

## Files in this repository

| Folder or file | Contents |
|----------------|----------|
| `Mutant_IDE_Code/` | Firmware: the updated sketch and the original sketch |
| `Eagle Files - PCB/` | Eagle files for the PCB |
| `Front Panel Design/` | KiCad, Inkscape and PNG files for the front panel |
| `Gerber Files/` | Gerber files for the PCB and the front panel, ready to order |
| `Parts List/` | Parts list |
| `Schematic.png` | Schematic |

## Why I made it

I want to make my own modular synth that is simple to build. Each module has these aims:

- It operates from 9 V (and 12 V).
- It is easy to build, with a minimum of components.
- It uses an Arduino, to keep the parts count low and everything in tune.
- It fits in any Eurorack case, and it can use normal Eurorack power.
- It sounds good.
- It is portable, and it can operate from a 9 V battery.

![Mutant module](https://github.com/user-attachments/assets/2f61441d-f15d-466a-be38-71519ba5a62b)

## Credits

- Synth design and code: [Meebleeps Mutant Synth](https://github.com/Meebleeps/MeeBleeps-Mutant-Synth). Thank you, Meebleeps.
- Audio library: [Mozzi](https://sensorium.github.io/Mozzi/).
- PCB, front panel, Eurorack version and the Mozzi 2 update: Marcus ([lonesoulsurfer](https://github.com/lonesoulsurfer)).

## Support

Do you like this project? You can support my work on [GitHub Sponsors](https://github.com/sponsors/lonesoulsurfer).

## Licence

This project uses the [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](LICENSE) (CC BY-NC-SA 4.0), the same licence as the Meebleeps original.

- You can build, share and change this project.
- You must name Meebleeps and lonesoulsurfer.
- You must not use it for commercial purposes. For example, do not sell kits or built synths.
- If you share a changed version, you must use the same licence.
