[Deutsch](apikeys-de.md) &bull; English

# API Keys

| Key        | R/W        | Type                         | Category      | Description                                                                         |
| ---------- | ---------- | ---------------------------- | ------------- | ----------------------------------------------------------------------------------- |
rst | W | TYPE | Unknown | Reset the controller
sse | R | TYPE | Constant | serial number
wifis | R/W | TYPE | Config | wifi configurations with ssids and keys, if you only want to change the second entry, send an array with 1 empty and 1 filled wifi config object: [{}, {"ssid":"","key":""}]
delw | W | TYPE | Unknown | set this to 0-9 to delete sta config (erases ssid, key, ...)
scan | R | TYPE | Status | wifi scan result (encryptionType: OPEN=0, WEP=1, WPA_PSK=2, WPA2_PSK=3, WPA_WPA2_PSK=4, WPA2_ENTERPRISE=5, WPA3_PSK=6, WPA2_WPA3_PSK=7)
lwf | R | TYPE | Status | last wifi connect failed (milliseconds since boot)
scaa | R | TYPE | Status | wifi scan age
wst | R | TYPE | Status | WiFi STA status (IDLE_STATUS=0, NO_SSID_AVAIL=1, SCAN_COMPLETED=2, CONNECTED=3, CONNECT_FAILED=4, CONNECTION_LOST=5, DISCONNECTED=6, CONNECTING=7, DISCONNECTING=8, NO_SHIELD=9, WAITING_FOR_IP=10)
wsc | R | TYPE | Status | WiFi STA error count
wsm | R | TYPE | Status | WiFi STA error message
wsl | R | TYPE | Status | WiFi STA error messages log
wsms | R | TYPE | Status | WiFi state machine state (None=0, Scanning=1, Connecting=2, Connected=3)
ccw | R | TYPE | Status | Currently connected WiFi
wfb | R | TYPE | Status | WiFi failed mac addresses (bssids)
wcb | R | TYPE | Status | WiFi current mac address (bssid connecting to)
wpb | R | TYPE | Status | WiFi planned mac addresses (future bssids)
nif | R | TYPE | Status | Default route
cce | R | TYPE | Status | Currently connected Ethernet
dns | R | TYPE | Status | dns servers
host | R | TYPE | Status | configured hostname
rssi | R | TYPE | Status | RSSI signal strength
wda | R/W | TYPE | Config | disable AccessPoint when cloud is connected
tse | R/W | TYPE | Config | time server enabled
tsss | R | TYPE | Status | time server sync status (RESET=0, COMPLETED=1, IN_PROGRESS=2)
tof | R/W | TYPE | Config | timezone offset in minutes
tds | R/W | TYPE | Config | timezone daylight saving mode, None=0, EuropeanSummerTime=1, UsDaylightTime=2
utc | R/W | TYPE | Status | utc time
loc | R | TYPE | Status | local time
fna | R/W | TYPE | Config | friendlyName
rbc | R | TYPE | Status | reboot_counter
rbt | R | TYPE | Status | time since boot in milliseconds
fwv | R | TYPE | Status | FW_VERSION
oem | R | TYPE | Constant | OEM manufacturer
typ | R | TYPE | Constant | Devicetype
awc | R/W | TYPE | Config | awattar country (Austria=0, Germany=1,...)
awp | R/W | TYPE | Config | awattarMaxPrice in ct
awcp | R | TYPE | Status | awattar current price
awpl | W | TYPE | Status | awattar price list, timestamps are measured in unix-time, seconds since 1970
hsa | W | TYPE | Config | httpStaAuthentication
oct | W | TYPE | Config | ota from cloud url trigger
ocu | R | TYPE | Config | ota from cloud url, url to download new firmware code from
cwe | R/W | TYPE | Config | cloud websocket enabled
clea | R | TYPE | Status | Cloud last error (age)
cle | R | TYPE | Status | Cloud last error
mme | R/W | TYPE | Config | modbus master enabled
mmh | R/W | TYPE | Config | modbus master host
mmp | R/W | TYPE | Config | modbus master port
men | R/W | TYPE | Config | modbus slave enabled
msp | R/W | TYPE | Config | modbus slave port (requires off/on toggle)
msb | R/W | TYPE | Config | modbus slave swap bytes
msr | R/W | TYPE | Config | modbus slave swap registers
data | R | TYPE | Status | grafana token from cloud for app
dll | R | TYPE | Status | download link for app csv export
hai | R/W | TYPE | Config | httpApiEnabled (allows /api/status and /api/set requests)
mce | R/W | TYPE | Config | MQTT enabled
mcu | R/W | TYPE | Config | MQTT broker url
mcr | R/W | TYPE | Config | MQTT readonly (don't allow api writes from mqtt broker)
mtp | R/W | TYPE | Config | MQTT topic prefix (set to null to reset back to the default)
mqg | R/W | TYPE | Config | MQTT useGlobalCaStore
mqcn | R/W | TYPE | Config | MQTT skipCertCommonNameCheck
mqss | R/W | TYPE | Config | MQTT skipServerVerification
mcs | R | TYPE | Status | MQTT started
mcc | R | TYPE | Status | MQTT connected
mcca | R | TYPE | Status | MQTT connected (age)
mlr | R | TYPE | Status | MQTT last error
mlra | R | TYPE | Status | MQTT last error (age)
ccn | R/W | TYPE | Config | controller category names
ccp | R | TYPE | Status | controller category powers
cec | R | TYPE | Status | controller energy counters
cpc | R | TYPE | Status | controller category phase currents
ccf | R/W | TYPE | Status | Controller category factors (outer array defines the current sensors, use isn for for current sensor names, the inner arrays are for each category, use ccn for the category names)
bri | R | TYPE | Status | brightness sensor
usn | R | TYPE | Config | voltage sensor names
usv | R | TYPE | Status | voltage sensor values (use usn for sensor names)
isn | R | TYPE | Config | current sensor names
isv | R | TYPE | Config | current sensor values (use isn for sensors names)
ips | R/W | TYPE | Config | current phase selections (for every current sensor (api key isn) a phase selection, L1=0, L2=1, L3=2, N=3)
iim | R/W | TYPE | Config | invert current measurement (for every current sensor (api key isn) an invert flag)
mece | R/W | TYPE | Config | mecmeterEnabled
mecu | R/W | TYPE | Config | mecmeterUrl
mecd | R | TYPE | Status | Mecmeter current data
mecf | R/W | TYPE | Status | Mecmeter category factors (outer array defines the 3 mecmeter loads, the inner arrays are for each category, use ccn for the category names)
