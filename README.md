# P-Nucleo-WB55_LedButton# STM32 Button-LED Interaction Project

This project demonstrates a simple interaction between buttons and LEDs using an STM32 microcontroller. When a button is pressed, its corresponding LED will light up.

## Hardware Requirements

- STM32 microcontroller board
- 3x Push buttons
- 3x LEDs

## Pin Configuration

- Button 1 is connected to pin `PC4`
- Button 2 is connected to pin `PD0`
- Button 3 is connected to pin `PD1`

- LED 1 is connected to pin `PB5`
- LED 2 is connected to pin `PB0`
- LED 3 is connected to pin `PB1`

## Software

The code is written in C++ for the Arduino platform. It uses a debouncing mechanism to handle button presses, ensuring that each button press results in a single action, even if there is noise in the signal.

## Usage

1. Upload the Arduino code to your STM32 board.
2. Press any of the buttons. Its corresponding LED should light up.
3. Release the button, and the LED should turn off.

## Debouncing

Debouncing is a technique used to ensure that only one switch press is registered even if the signal is noisy. This is achieved by waiting for a small delay after the button state changes before reading the button state again.

## Contributing

If you'd like to contribute to this project, please open an issue or submit a pull request.

## License

This project is open source and available under the MIT License.
