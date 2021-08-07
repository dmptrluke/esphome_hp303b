# esphome_hp303b
An ESPHome custom sensor component for the HP303B barometric pressure sensor.

An example of how to use this file is below:

```yaml
esphome:
  name: barometric_pressure_sample
  platform: ESP8266
  board: d1_mini
  libraries:
    - "https://github.com/wemos/LOLIN_HP303B_Library" # lib from github
    - "SPI" # lib from platformio
  includes:
    - hp303b.h

  
sensor:
  - platform: custom
    lambda: |-
      auto hp_sensor = new HP303BSensor();
      App.register_component(hp_sensor);
      return {hp_sensor};

    sensors:
      name: "Barometric Pressure"
      icon: "mdi:gauge"
      unit_of_measurement: hPa
      accuracy_decimals: 1
```
