Deutsch &bull; [English](modbus-en.md)

# Modbus

Die go-eController bieten ein Modbus TCP Interface an, mit dem einige Leistungs- und Energiewerte abgefragt werden können. Dieses Interface muss erst über die App oder [http API](http-de.md) aktiviert werden.

Live-Messwerte können über die [Modbus Funktion 4](https://www.simplymodbus.ca/FC04.htm) abgeholt werden.

Einstellungen können über die [Modbus Funktion 3](https://www.simplymodbus.ca/FC03.htm) gelesen und über die [Modbus Funktion 16](https://www.simplymodbus.ca/FC16.htm) gesetzt werden.

Nach Aktivierung kann der TCP Port 502 verwendet werden.

| Funktion Nr | Name                      | Unterstützt?                                 |
| ----------- | ------------------------- | -------------------------------------------- |
| 01          | Read Coil Status          | Nein                                         |
| 02          | Read Input Status         | Nein                                         |
| 03          | Read Holding Registers    | Ja, für alle Live-Werte unten aufgelistet    |
| 04          | Read Input Registers      | Ja, für alle Einstellungen unten aufgelistet |
| 05          | Force Single Coil         | Nein                                         |
| 06          | Preset Single Register    | Nein                                         |
| 15          | Force Multiple Coils      | Nein                                         |
| 16          | Read Input Registers      | Ja, für alle Einstellungen unten aufgelistet |

## Über die App das Modbus Interface aktivieren und prüfen

Unten im Tab "Internet", dann "Erweiterte Einstelluingen" im Menü anwählen, dann relativ weit unten bei Modbus

<img src="screenshots/modbus-app-enable.png?raw=true" width="200" />

## Über die http API das Modbus interface aktivieren und prüfen

Die Chargers verfügen über API Keys zum Konfigurieren und Prüfen des Modbus interface. Diese API Keys können mit der http api verwendet werden.

Beispiel: http://192.168.0.77/api/set?men=true

| api key | Beschreibung                 | Datentyp | R?W? | Kategorie |
| ------- | ---------------------------- | -------- | ---- | --------- |
| men     | modbus slave aktiviert       | bool     | R/W  | Config    |
| msp     | modbus slave port (erfordert Neustart) | uint16 | R/W | Config |
| msb     | modbus slave Bytes vertauschen | bool     | R/W  | Config    |
| msr     | modbus slave Register vertauschen | bool     | R/W  | Config    |
| mro     | modbus slave Lese-Operationen | size_t   | R    | Status    |
| mwo     | modbus slave Schreib-Operationen | size_t  | R    | Status    |

## Modbus Profil

### Input Registers (read-only)

Daten in dieser Tabelle können mit der Modbus Funktion 04 gelesen werden.

<!-- MODBUS TABLE BEGIN -->
| Register                                                                 | Registertyp | Datentyp | Name                         | Einheit          | Beschreibung |
| ------------------------------------------------------------------------ | ----------- | -------- | ---------------------------- | ---------------- | ------------ |
| <!-- MODBUS-SET-ADDR: 31001 -->                                          |             |          |                              |                  |              |
| 31001 (1000) <br /> 31002 (1001)                                         | Input       | Float32  | Voltage L1                   | V (Volt)         |              |
| 31003 (1002) <br /> 31004 (1003)                                         | Input       | Float32  | Voltage L2                   | V (Volt)         |              |
| 31005 (1004) <br /> 31006 (1005)                                         | Input       | Float32  | Voltage L3                   | V (Volt)         |              |
| 31007 (1006) <br /> 31008 (1007)                                         | Input       | Float32  | Voltage N                    | V (Volt)         |              |
| 31009 (1008) <br /> 31010 (1009)                                         | Input       | Float32  | Frequency                    | Hz (Herz)        |              |
| 31011 (1010) <br /> 31012 (1011)                                         | Input       | Float32  | Current Sensor 1 Current     | A (Ampere)       |              |
| 31013 (1012) <br /> 31014 (1013)                                         | Input       | Float32  | Current Sensor 2 Current     | A (Ampere)       |              |
| 31015 (1014) <br /> 31016 (1015)                                         | Input       | Float32  | Current Sensor 3 Current     | A (Ampere)       |              |
| 31017 (1016) <br /> 31018 (1017)                                         | Input       | Float32  | Current Sensor 4 Current     | A (Ampere)       |              |
| 31019 (1018) <br /> 31020 (1019)                                         | Input       | Float32  | Current Sensor 5 Current     | A (Ampere)       |              |
| 31021 (1020) <br /> 31022 (1021)                                         | Input       | Float32  | Current Sensor 6 Current     | A (Ampere)       |              |
| 31023 (1022) <br /> 31024 (1023)                                         | Input       | Float32  | Current Sensor 1 Power       | W (Watt)         |              |
| 31025 (1024) <br /> 31026 (1025)                                         | Input       | Float32  | Current Sensor 2 Power       | W (Watt)         |              |
| 31027 (1026) <br /> 31028 (1027)                                         | Input       | Float32  | Current Sensor 3 Power       | W (Watt)         |              |
| 31029 (1028) <br /> 31030 (1029)                                         | Input       | Float32  | Current Sensor 4 Power       | W (Watt)         |              |
| 31031 (1030) <br /> 31032 (1031)                                         | Input       | Float32  | Current Sensor 5 Power       | W (Watt)         |              |
| 31033 (1032) <br /> 31034 (1033)                                         | Input       | Float32  | Current Sensor 6 Power       | W (Watt)         |              |
| 31035 (1034) <br /> 31036 (1035)                                         | Input       | Float32  | Current Sensor 1 Powerfactor | Factor 0.0 - 1.0 |              |
| 31037 (1036) <br /> 31038 (1037)                                         | Input       | Float32  | Current Sensor 2 Powerfactor | Factor 0.0 - 1.0 |              |
| 31039 (1038) <br /> 31040 (1039)                                         | Input       | Float32  | Current Sensor 3 Powerfactor | Factor 0.0 - 1.0 |              |
| 31041 (1040) <br /> 31042 (1041)                                         | Input       | Float32  | Current Sensor 4 Powerfactor | Factor 0.0 - 1.0 |              |
| 31043 (1042) <br /> 31044 (1043)                                         | Input       | Float32  | Current Sensor 5 Powerfactor | Factor 0.0 - 1.0 |              |
| 31045 (1044) <br /> 31046 (1045)                                         | Input       | Float32  | Current Sensor 6 Powerfactor | Factor 0.0 - 1.0 |              |
| 31047 (1046) <br /> 31048 (1047)                                         | Input       | Float32  | Category Home Current L1     | A (Ampere)       |              |
| 31049 (1048) <br /> 31050 (1049)                                         | Input       | Float32  | Category Home Current L2     | A (Ampere)       |              |
| 31051 (1050) <br /> 31052 (1051)                                         | Input       | Float32  | Category Home Current L3     | A (Ampere)       |              |
| 31053 (1052) <br /> 31054 (1053)                                         | Input       | Float32  | Category Home Power          | W (Watt)         |              |
| 31055 (1054) <br /> 31056 (1055) <br /> 31057 (1056) <br /> 31058 (1057) | Input       | Float64  | Category Home Energy In      | Wh (Watt-Hours)  |              |
| 31059 (1058) <br /> 31060 (1059) <br /> 31061 (1060) <br /> 31062 (1061) | Input       | Float64  | Category Home Energy Out     | Wh (Watt-Hours)  |              |
| 31063 (1062) <br /> 31064 (1063) <br /> 31065 (1064) <br /> 31066 (1065) | Input       | Float64  | Category Home Money In       | Money            |              |
| 31067 (1066) <br /> 31068 (1067) <br /> 31069 (1068) <br /> 31070 (1069) | Input       | Float64  | Category Home Money Out      | Money            |              |
| 31071 (1070) <br /> 31072 (1071)                                         | Input       | Float32  | Category Grid Current L1     | A (Ampere)       |              |
| 31073 (1072) <br /> 31074 (1073)                                         | Input       | Float32  | Category Grid Current L2     | A (Ampere)       |              |
| 31075 (1074) <br /> 31076 (1075)                                         | Input       | Float32  | Category Grid Current L3     | A (Ampere)       |              |
| 31077 (1076) <br /> 31078 (1077)                                         | Input       | Float32  | Category Grid Power          | W (Watt)         |              |
| 31079 (1078) <br /> 31080 (1079) <br /> 31081 (1080) <br /> 31082 (1081) | Input       | Float64  | Category Grid Energy In      | Wh (Watt-Hours)  |              |
| 31083 (1082) <br /> 31084 (1083) <br /> 31085 (1084) <br /> 31086 (1085) | Input       | Float64  | Category Grid Energy Out     | Wh (Watt-Hours)  |              |
| 31087 (1086) <br /> 31088 (1087) <br /> 31089 (1088) <br /> 31090 (1089) | Input       | Float64  | Category Grid Money In       | Money            |              |
| 31091 (1090) <br /> 31092 (1091) <br /> 31093 (1092) <br /> 31094 (1093) | Input       | Float64  | Category Grid Money Out      | Money            |              |
| 31095 (1094) <br /> 31096 (1095)                                         | Input       | Float32  | Category Car Current L1      | A (Ampere)       |              |
| 31097 (1096) <br /> 31098 (1097)                                         | Input       | Float32  | Category Car Current L2      | A (Ampere)       |              |
| 31099 (1098) <br /> 31100 (1099)                                         | Input       | Float32  | Category Car Current L3      | A (Ampere)       |              |
| 31101 (1100) <br /> 31102 (1101)                                         | Input       | Float32  | Category Car Power           | W (Watt)         |              |
| 31103 (1102) <br /> 31104 (1103) <br /> 31105 (1104) <br /> 31106 (1105) | Input       | Float64  | Category Car Energy In       | Wh (Watt-Hours)  |              |
| 31107 (1106) <br /> 31108 (1107) <br /> 31109 (1108) <br /> 31110 (1109) | Input       | Float64  | Category Car Energy Out      | Wh (Watt-Hours)  |              |
| 31111 (1110) <br /> 31112 (1111) <br /> 31113 (1112) <br /> 31114 (1113) | Input       | Float64  | Category Car Money In        | Money            |              |
| 31115 (1114) <br /> 31116 (1115) <br /> 31117 (1116) <br /> 31118 (1117) | Input       | Float64  | Category Car Money Out       | Money            |              |
| 31119 (1118) <br /> 31120 (1119)                                         | Input       | Float32  | Category Relais Current L1   | A (Ampere)       |              |
| 31121 (1120) <br /> 31122 (1121)                                         | Input       | Float32  | Category Relais Current L2   | A (Ampere)       |              |
| 31123 (1122) <br /> 31124 (1123)                                         | Input       | Float32  | Category Relais Current L3   | A (Ampere)       |              |
| 31125 (1124) <br /> 31126 (1125)                                         | Input       | Float32  | Category Relais Power        | W (Watt)         |              |
| 31127 (1126) <br /> 31128 (1127) <br /> 31129 (1128) <br /> 31130 (1129) | Input       | Float64  | Category Relais Energy In    | Wh (Watt-Hours)  |              |
| 31131 (1130) <br /> 31132 (1131) <br /> 31133 (1132) <br /> 31134 (1133) | Input       | Float64  | Category Relais Energy Out   | Wh (Watt-Hours)  |              |
| 31135 (1134) <br /> 31136 (1135) <br /> 31137 (1136) <br /> 31138 (1137) | Input       | Float64  | Category Relais Money In     | Money            |              |
| 31139 (1138) <br /> 31140 (1139) <br /> 31141 (1140) <br /> 31142 (1141) | Input       | Float64  | Category Relais Money Out    | Money            |              |
| 31143 (1142) <br /> 31144 (1143)                                         | Input       | Float32  | Category Solar Current L1    | A (Ampere)       |              |
| 31145 (1144) <br /> 31146 (1145)                                         | Input       | Float32  | Category Solar Current L2    | A (Ampere)       |              |
| 31147 (1146) <br /> 31148 (1147)                                         | Input       | Float32  | Category Solar Current L3    | A (Ampere)       |              |
| 31149 (1148) <br /> 31150 (1149)                                         | Input       | Float32  | Category Solar Power         | W (Watt)         |              |
| 31151 (1150) <br /> 31152 (1151) <br /> 31153 (1152) <br /> 31154 (1153) | Input       | Float64  | Category Solar Energy In     | Wh (Watt-Hours)  |              |
| 31155 (1154) <br /> 31156 (1155) <br /> 31157 (1156) <br /> 31158 (1157) | Input       | Float64  | Category Solar Energy Out    | Wh (Watt-Hours)  |              |
| 31159 (1158) <br /> 31160 (1159) <br /> 31161 (1160) <br /> 31162 (1161) | Input       | Float64  | Category Solar Money In      | Money            |              |
| 31163 (1162) <br /> 31164 (1163) <br /> 31165 (1164) <br /> 31166 (1165) | Input       | Float64  | Category Solar Money Out     | Money            |              |
| 31167 (1166) <br /> 31168 (1167)                                         | Input       | Float32  | Category Akku Current L1     | A (Ampere)       |              |
| 31169 (1168) <br /> 31170 (1169)                                         | Input       | Float32  | Category Akku Current L2     | A (Ampere)       |              |
| 31171 (1170) <br /> 31172 (1171)                                         | Input       | Float32  | Category Akku Current L3     | A (Ampere)       |              |
| 31173 (1172) <br /> 31174 (1173)                                         | Input       | Float32  | Category Akku Power          | W (Watt)         |              |
| 31175 (1174) <br /> 31176 (1175) <br /> 31177 (1176) <br /> 31178 (1177) | Input       | Float64  | Category Akku Energy In      | Wh (Watt-Hours)  |              |
| 31179 (1178) <br /> 31180 (1179) <br /> 31181 (1180) <br /> 31182 (1181) | Input       | Float64  | Category Akku Energy Out     | Wh (Watt-Hours)  |              |
| 31183 (1182) <br /> 31184 (1183) <br /> 31185 (1184) <br /> 31186 (1185) | Input       | Float64  | Category Akku Money In       | Money            |              |
| 31187 (1186) <br /> 31188 (1187) <br /> 31189 (1188) <br /> 31190 (1189) | Input       | Float64  | Category Akku Money Out      | Money            |              |
| <!-- MODBUS-SKIP-ADDR: 24 -->                                            |             |          |                              |                  |              |
| <!-- MODBUS-SKIP-ADDR: 24 -->                                            |             |          |                              |                  |              |
| <!-- MODBUS-SKIP-ADDR: 24 -->                                            |             |          |                              |                  |              |
| <!-- MODBUS-SKIP-ADDR: 24 -->                                            |             |          |                              |                  |              |
| 31287 (1286) <br /> 31288 (1287)                                         | Input       | Float32  | Custom Category 0 Current L1 | A (Ampere)       |              |
| 31289 (1288) <br /> 31290 (1289)                                         | Input       | Float32  | Custom Category 0 Current L2 | A (Ampere)       |              |
| 31291 (1290) <br /> 31292 (1291)                                         | Input       | Float32  | Custom Category 0 Current L3 | A (Ampere)       |              |
| 31293 (1292) <br /> 31294 (1293)                                         | Input       | Float32  | Custom Category 0 Power      | W (Watt)         |              |
| 31295 (1294) <br /> 31296 (1295) <br /> 31297 (1296) <br /> 31298 (1297) | Input       | Float64  | Custom Category 0 Energy In  | Wh (Watt-Hours)  |              |
| 31299 (1298) <br /> 31300 (1299) <br /> 31301 (1300) <br /> 31302 (1301) | Input       | Float64  | Custom Category 0 Energy Out | Wh (Watt-Hours)  |              |
| 31303 (1302) <br /> 31304 (1303) <br /> 31305 (1304) <br /> 31306 (1305) | Input       | Float64  | Custom Category 0 Money In   | Money            |              |
| 31307 (1306) <br /> 31308 (1307) <br /> 31309 (1308) <br /> 31310 (1309) | Input       | Float64  | Custom Category 0 Money Out  | Money            |              |
| 31311 (1310) <br /> 31312 (1311)                                         | Input       | Float32  | Custom Category 1 Current L1 | A (Ampere)       |              |
| 31313 (1312) <br /> 31314 (1313)                                         | Input       | Float32  | Custom Category 1 Current L2 | A (Ampere)       |              |
| 31315 (1314) <br /> 31316 (1315)                                         | Input       | Float32  | Custom Category 1 Current L3 | A (Ampere)       |              |
| 31317 (1316) <br /> 31318 (1317)                                         | Input       | Float32  | Custom Category 1 Power      | W (Watt)         |              |
| 31319 (1318) <br /> 31320 (1319) <br /> 31321 (1320) <br /> 31322 (1321) | Input       | Float64  | Custom Category 1 Energy In  | Wh (Watt-Hours)  |              |
| 31323 (1322) <br /> 31324 (1323) <br /> 31325 (1324) <br /> 31326 (1325) | Input       | Float64  | Custom Category 1 Energy Out | Wh (Watt-Hours)  |              |
| 31327 (1326) <br /> 31328 (1327) <br /> 31329 (1328) <br /> 31330 (1329) | Input       | Float64  | Custom Category 1 Money In   | Money            |              |
| 31331 (1330) <br /> 31332 (1331) <br /> 31333 (1332) <br /> 31334 (1333) | Input       | Float64  | Custom Category 1 Money Out  | Money            |              |
| 31335 (1334) <br /> 31336 (1335)                                         | Input       | Float32  | Custom Category 2 Current L1 | A (Ampere)       |              |
| 31337 (1336) <br /> 31338 (1337)                                         | Input       | Float32  | Custom Category 2 Current L2 | A (Ampere)       |              |
| 31339 (1338) <br /> 31340 (1339)                                         | Input       | Float32  | Custom Category 2 Current L3 | A (Ampere)       |              |
| 31341 (1340) <br /> 31342 (1341)                                         | Input       | Float32  | Custom Category 2 Power      | W (Watt)         |              |
| 31343 (1342) <br /> 31344 (1343) <br /> 31345 (1344) <br /> 31346 (1345) | Input       | Float64  | Custom Category 2 Energy In  | Wh (Watt-Hours)  |              |
| 31347 (1346) <br /> 31348 (1347) <br /> 31349 (1348) <br /> 31350 (1349) | Input       | Float64  | Custom Category 2 Energy Out | Wh (Watt-Hours)  |              |
| 31351 (1350) <br /> 31352 (1351) <br /> 31353 (1352) <br /> 31354 (1353) | Input       | Float64  | Custom Category 2 Money In   | Money            |              |
| 31355 (1354) <br /> 31356 (1355) <br /> 31357 (1356) <br /> 31358 (1357) | Input       | Float64  | Custom Category 2 Money Out  | Money            |              |
| 31359 (1358) <br /> 31360 (1359)                                         | Input       | Float32  | Custom Category 3 Current L1 | A (Ampere)       |              |
| 31361 (1360) <br /> 31362 (1361)                                         | Input       | Float32  | Custom Category 3 Current L2 | A (Ampere)       |              |
| 31363 (1362) <br /> 31364 (1363)                                         | Input       | Float32  | Custom Category 3 Current L3 | A (Ampere)       |              |
| 31365 (1364) <br /> 31366 (1365)                                         | Input       | Float32  | Custom Category 3 Power      | W (Watt)         |              |
| 31367 (1366) <br /> 31368 (1367) <br /> 31369 (1368) <br /> 31370 (1369) | Input       | Float64  | Custom Category 3 Energy In  | Wh (Watt-Hours)  |              |
| 31371 (1370) <br /> 31372 (1371) <br /> 31373 (1372) <br /> 31374 (1373) | Input       | Float64  | Custom Category 3 Energy Out | Wh (Watt-Hours)  |              |
| 31375 (1374) <br /> 31376 (1375) <br /> 31377 (1376) <br /> 31378 (1377) | Input       | Float64  | Custom Category 3 Money In   | Money            |              |
| 31379 (1378) <br /> 31380 (1379) <br /> 31381 (1380) <br /> 31382 (1381) | Input       | Float64  | Custom Category 3 Money Out  | Money            |              |
| 31383 (1382) <br /> 31384 (1383)                                         | Input       | Float32  | Custom Category 4 Current L1 | A (Ampere)       |              |
| 31385 (1384) <br /> 31386 (1385)                                         | Input       | Float32  | Custom Category 4 Current L2 | A (Ampere)       |              |
| 31387 (1386) <br /> 31388 (1387)                                         | Input       | Float32  | Custom Category 4 Current L3 | A (Ampere)       |              |
| 31389 (1388) <br /> 31390 (1389)                                         | Input       | Float32  | Custom Category 4 Power      | W (Watt)         |              |
| 31391 (1390) <br /> 31392 (1391) <br /> 31393 (1392) <br /> 31394 (1393) | Input       | Float64  | Custom Category 4 Energy In  | Wh (Watt-Hours)  |              |
| 31395 (1394) <br /> 31396 (1395) <br /> 31397 (1396) <br /> 31398 (1397) | Input       | Float64  | Custom Category 4 Energy Out | Wh (Watt-Hours)  |              |
| 31399 (1398) <br /> 31400 (1399) <br /> 31401 (1400) <br /> 31402 (1401) | Input       | Float64  | Custom Category 4 Money In   | Money            |              |
| 31403 (1402) <br /> 31404 (1403) <br /> 31405 (1404) <br /> 31406 (1405) | Input       | Float64  | Custom Category 4 Money Out  | Money            |              |
| 31407 (1406) <br /> 31408 (1407)                                         | Input       | Float32  | Custom Category 5 Current L1 | A (Ampere)       |              |
| 31409 (1408) <br /> 31410 (1409)                                         | Input       | Float32  | Custom Category 5 Current L2 | A (Ampere)       |              |
| 31411 (1410) <br /> 31412 (1411)                                         | Input       | Float32  | Custom Category 5 Current L3 | A (Ampere)       |              |
| 31413 (1412) <br /> 31414 (1413)                                         | Input       | Float32  | Custom Category 5 Power      | W (Watt)         |              |
| 31415 (1414) <br /> 31416 (1415) <br /> 31417 (1416) <br /> 31418 (1417) | Input       | Float64  | Custom Category 5 Energy In  | Wh (Watt-Hours)  |              |
| 31419 (1418) <br /> 31420 (1419) <br /> 31421 (1420) <br /> 31422 (1421) | Input       | Float64  | Custom Category 5 Energy Out | Wh (Watt-Hours)  |              |
| 31423 (1422) <br /> 31424 (1423) <br /> 31425 (1424) <br /> 31426 (1425) | Input       | Float64  | Custom Category 5 Money In   | Money            |              |
| 31427 (1426) <br /> 31428 (1427) <br /> 31429 (1428) <br /> 31430 (1429) | Input       | Float64  | Custom Category 5 Money Out  | Money            |              |
| 31431 (1430) <br /> 31432 (1431)                                         | Input       | Float32  | Custom Category 6 Current L1 | A (Ampere)       |              |
| 31433 (1432) <br /> 31434 (1433)                                         | Input       | Float32  | Custom Category 6 Current L2 | A (Ampere)       |              |
| 31435 (1434) <br /> 31436 (1435)                                         | Input       | Float32  | Custom Category 6 Current L3 | A (Ampere)       |              |
| 31437 (1436) <br /> 31438 (1437)                                         | Input       | Float32  | Custom Category 6 Power      | W (Watt)         |              |
| 31439 (1438) <br /> 31440 (1439) <br /> 31441 (1440) <br /> 31442 (1441) | Input       | Float64  | Custom Category 6 Energy In  | Wh (Watt-Hours)  |              |
| 31443 (1442) <br /> 31444 (1443) <br /> 31445 (1444) <br /> 31446 (1445) | Input       | Float64  | Custom Category 6 Energy Out | Wh (Watt-Hours)  |              |
| 31447 (1446) <br /> 31448 (1447) <br /> 31449 (1448) <br /> 31450 (1449) | Input       | Float64  | Custom Category 6 Money In   | Money            |              |
| 31451 (1450) <br /> 31452 (1451) <br /> 31453 (1452) <br /> 31454 (1453) | Input       | Float64  | Custom Category 6 Money Out  | Money            |              |
| 31455 (1454) <br /> 31456 (1455)                                         | Input       | Float32  | Custom Category 7 Current L1 | A (Ampere)       |              |
| 31457 (1456) <br /> 31458 (1457)                                         | Input       | Float32  | Custom Category 7 Current L2 | A (Ampere)       |              |
| 31459 (1458) <br /> 31460 (1459)                                         | Input       | Float32  | Custom Category 7 Current L3 | A (Ampere)       |              |
| 31461 (1460) <br /> 31462 (1461)                                         | Input       | Float32  | Custom Category 7 Power      | W (Watt)         |              |
| 31463 (1462) <br /> 31464 (1463) <br /> 31465 (1464) <br /> 31466 (1465) | Input       | Float64  | Custom Category 7 Energy In  | Wh (Watt-Hours)  |              |
| 31467 (1466) <br /> 31468 (1467) <br /> 31469 (1468) <br /> 31470 (1469) | Input       | Float64  | Custom Category 7 Energy Out | Wh (Watt-Hours)  |              |
| 31471 (1470) <br /> 31472 (1471) <br /> 31473 (1472) <br /> 31474 (1473) | Input       | Float64  | Custom Category 7 Money In   | Money            |              |
| 31475 (1474) <br /> 31476 (1475) <br /> 31477 (1476) <br /> 31478 (1477) | Input       | Float64  | Custom Category 7 Money Out  | Money            |              |
| 31479 (1478) <br /> 31480 (1479)                                         | Input       | Float32  | Custom Category 8 Current L1 | A (Ampere)       |              |
| 31481 (1480) <br /> 31482 (1481)                                         | Input       | Float32  | Custom Category 8 Current L2 | A (Ampere)       |              |
| 31483 (1482) <br /> 31484 (1483)                                         | Input       | Float32  | Custom Category 8 Current L3 | A (Ampere)       |              |
| 31485 (1484) <br /> 31486 (1485)                                         | Input       | Float32  | Custom Category 8 Power      | W (Watt)         |              |
| 31487 (1486) <br /> 31488 (1487) <br /> 31489 (1488) <br /> 31490 (1489) | Input       | Float64  | Custom Category 8 Energy In  | Wh (Watt-Hours)  |              |
| 31491 (1490) <br /> 31492 (1491) <br /> 31493 (1492) <br /> 31494 (1493) | Input       | Float64  | Custom Category 8 Energy Out | Wh (Watt-Hours)  |              |
| 31495 (1494) <br /> 31496 (1495) <br /> 31497 (1496) <br /> 31498 (1497) | Input       | Float64  | Custom Category 8 Money In   | Money            |              |
| 31499 (1498) <br /> 31500 (1499) <br /> 31501 (1500) <br /> 31502 (1501) | Input       | Float64  | Custom Category 8 Money Out  | Money            |              |
| 31503 (1502) <br /> 31504 (1503)                                         | Input       | Float32  | Custom Category 9 Current L1 | A (Ampere)       |              |
| 31505 (1504) <br /> 31506 (1505)                                         | Input       | Float32  | Custom Category 9 Current L2 | A (Ampere)       |              |
| 31507 (1506) <br /> 31508 (1507)                                         | Input       | Float32  | Custom Category 9 Current L3 | A (Ampere)       |              |
| 31509 (1508) <br /> 31510 (1509)                                         | Input       | Float32  | Custom Category 9 Power      | W (Watt)         |              |
| 31511 (1510) <br /> 31512 (1511) <br /> 31513 (1512) <br /> 31514 (1513) | Input       | Float64  | Custom Category 9 Energy In  | Wh (Watt-Hours)  |              |
| 31515 (1514) <br /> 31516 (1515) <br /> 31517 (1516) <br /> 31518 (1517) | Input       | Float64  | Custom Category 9 Energy Out | Wh (Watt-Hours)  |              |
| 31519 (1518) <br /> 31520 (1519) <br /> 31521 (1520) <br /> 31522 (1521) | Input       | Float64  | Custom Category 9 Money In   | Money            |              |
| 31523 (1522) <br /> 31524 (1523) <br /> 31525 (1524) <br /> 31526 (1525) | Input       | Float64  | Custom Category 9 Money Out  | Money            |              |
<!-- MODBUS TABLE END -->

### Holding Registers (read-write)

Daten in dieser Tabelle können mit der Modbus Funktion 03 gelesen und mit der Modbus Funktion 16 geschrieben werden.

<!-- MODBUS TABLE BEGIN -->
| Register                                                     | Registertyp | Datentyp | Name                   | Einheit       | Beschreibung |
| ------------------------------------------------------------ | ----------- | -------- | ---------------------- | ------------- | ------------ |
| <!-- MODBUS-SET-ADDR: 40001 -->                              |             |          |                        |               |              |
| 40001 (0) <br /> 40002 (1) <br /> 40003 (2) <br /> 40004 (3) | Holding     | Int64    | Unix-Zeitstempel (UTC) | Millisekunden |              |
<!-- MODBUS TABLE END -->
