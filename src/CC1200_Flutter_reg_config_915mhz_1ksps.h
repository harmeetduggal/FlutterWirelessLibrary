/*
  Flutter is a lightweight wireless library for embedded systems.
  Copyright (c) 2015 Flutter Wireless. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  The license is also available here:
  https://www.gnu.org/licenses/lgpl-2.1.html
*/


// Carrier frequency = 915.000000 
// Manchester enable = false 
// Whitening = true 
// Symbol rate = 1.2 
// Device address = 0 
// Modulation format = 2-FSK 
// RX filter BW = 10.964912 
// Packet length = 255 
// Deviation = 3.986359 
// Address config = No address check 
// Packet length mode = Variable 
// Packet bit length = 0 
// Bit rate = 1.2 

typedef struct
{
int addr;
byte data;
} registerSettings;

static const registerSettings settings[] = {
    {REG_RFEND_CFG1,        (0x3<<4)|(0x7<<1)}, //auto RX
    {REG_RFEND_CFG0,        (0x3<<4)}, //auto RX
    {REG_IOCFG0,        0x06},
    {REG_IOCFG3,        0x30},
    {REG_IOCFG2,        0x30},
    {REG_PKT_CFG1,      (0x1<<0)|(0x1<<1)|(0x10<<3)|(0x1<<6)}, // PKT_CFG1  Packet Configuration Reg. 1 - Address check, CRC default on, whiten data

    {REG_SYNC_CFG1, 0xAB},       // SYNC_CFG1           Sync Word Detection Configuration Reg. 1
    {REG_DEVIATION_M, 0xD1},     // DEVIATION_M         Frequency Deviation Configuration
    {REG_MODCFG_DEV_E, 0x00},    // MODCFG_DEV_E        Modulation Format and Frequency Deviation Configur..
    {REG_DCFILT_CFG, 0x5D},      // DCFILT_CFG          Digital DC Removal Configuration
    {REG_PREAMBLE_CFG0, 0x8A},   // PREAMBLE_CFG0       Preamble Detection Configuration Reg. 0
    {REG_IQIC, 0xCB},            // IQIC                Digital Image Channel Compensation Configuration
    {REG_CHAN_BW, 0xA6},         // CHAN_BW             Channel Filter Configuration
    {REG_MDMCFG1, 0x40},         // MDMCFG1             General Modem Parameter Configuration Reg. 1
    {REG_MDMCFG0, 0x05},         // MDMCFG0             General Modem Parameter Configuration Reg. 0
    {REG_SYMBOL_RATE2, 0x3F},    // SYMBOL_RATE2        Symbol Rate Configuration Exponent and Mantissa [1..
    {REG_SYMBOL_RATE1, 0x75},    // SYMBOL_RATE1        Symbol Rate Configuration Mantissa [15:8]
    {REG_SYMBOL_RATE0, 0x10},    // SYMBOL_RATE0        Symbol Rate Configuration Mantissa [7:0]
    {REG_AGC_REF, 0x20},         // AGC_REF             AGC Reference Level Configuration
    {REG_AGC_CS_THR, 0xEC},      // AGC_CS_THR          Carrier Sense Threshold Configuration
    {REG_AGC_CFG1, 0x51},        // AGC_CFG1            Automatic Gain Control Configuration Reg. 1
    {REG_AGC_CFG0, 0x87},        // AGC_CFG0            Automatic Gain Control Configuration Reg. 0
    {REG_FIFO_CFG, 0x00},        // FIFO_CFG            FIFO Configuration
    {REG_FS_CFG, 0x12},          // FS_CFG              Frequency Synthesizer Configuration
    {REG_PKT_CFG2, 0x00},        // PKT_CFG2            Packet Configuration Reg. 2
    {REG_PKT_CFG0, 0x20},        // PKT_CFG0            Packet Configuration Reg. 0
    {REG_PKT_LEN, 0xFF},         // PKT_LEN             Packet Length Configuration
    {REG_IF_MIX_CFG, 0x1C},      // IF_MIX_CFG          IF Mix Configuration
    {REG_FREQOFF_CFG, 0x22},     // FREQOFF_CFG         Frequency Offset Correction Configuration
    {REG_MDMCFG2, 0x0C},         // MDMCFG2             General Modem Parameter Configuration Reg. 2
    {REG_FREQ2, 0x5B},           // FREQ2               Frequency Configuration [23:16]
    {REG_FREQ1, 0x80},           // FREQ1               Frequency Configuration [15:8]
    {REG_IF_ADC1, 0xEE},         // IF_ADC1             Analog to Digital Converter Configuration Reg. 1
    {REG_IF_ADC0, 0x10},         // IF_ADC0             Analog to Digital Converter Configuration Reg. 0
    {REG_FS_DIG1, 0x07},         // FS_DIG1             Frequency Synthesizer Digital Reg. 1
    {REG_FS_DIG0, 0xAF},         // FS_DIG0             Frequency Synthesizer Digital Reg. 0
    {REG_FS_CAL1, 0x40},         // FS_CAL1             Frequency Synthesizer Calibration Reg. 1
    {REG_FS_CAL0, 0x0E},         // FS_CAL0             Frequency Synthesizer Calibration Reg. 0
    {REG_FS_DIVTWO, 0x03},       // FS_DIVTWO           Frequency Synthesizer Divide by 2
    {REG_FS_DSM0, 0x33},         // FS_DSM0             FS Digital Synthesizer Module Configuration Reg. 0
    {REG_FS_DVC0, 0x17},         // FS_DVC0             Frequency Synthesizer Divider Chain Configuration ..
    {REG_FS_PFD, 0x00},          // FS_PFD              Frequency Synthesizer Phase Frequency Detector Con..
    {REG_FS_PRE, 0x6E},          // FS_PRE              Frequency Synthesizer Prescaler Configuration
    {REG_FS_REG_DIV_CML, 0x1C},  // FS_REG_DIV_CML      Frequency Synthesizer Divider Regulator Configurat..
    {REG_FS_SPARE, 0xAC},        // FS_SPARE            Frequency Synthesizer Spare
    {REG_FS_VCO0, 0xB5},         // FS_VCO0             FS Voltage Controlled Oscillator Configuration Reg..
    {REG_XOSC5, 0x0E},           // XOSC5               Crystal Oscillator Configuration Reg. 5
    {REG_XOSC1, 0x03},           // XOSC1               Crystal Oscillator Configuration Reg. 1
		};