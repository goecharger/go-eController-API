Deutsch &bull; [English](http-en.md)

# HTTP Api

[Die API Keys](apikeys-de.md) können über die HTTP Api gelesen und geschrieben werden.

Dafür muss die HTTP API (v2) in der App erst aktiviert werden:

<img src="screenshots/http-api-app-enable.png?raw=true" width="200" />

## Alle Werte auf einmal abfragen
<small>höhere Last am System, viel traffic, sollte nicht für den Dauerbetrieb benutzt werden</small>

`http://192.168.0.99/api/status`

<img src="screenshots/http-api-status.png?raw=true" />

## Vereinzelte Werte abfragen
Um die erhöhte Last zu reduzieren, kann die Status Anfrage so gefiltert werden, dass nur bestimmte Api Keys in der Response vor kommen.

`http://192.168.0.75/api/status?filter=ccn,ccp,cec`

<img src="screenshots/http-api-status-filtered.png?raw=true" />

## Werte setzen
Jeder zu setzende api wert muss als Url Query parameter (GET Parameter) mitgegeben werden. Der Wert muss dabei als JSON encodiert werden. Bei Strings zB dürfen die Anführungszeichen davor und danach nicht fehlen.

```
http://192.168.0.75/api/set?fna="mein controller"
http://192.168.0.75/api/set?ccn=[null,null,null,null,null,null,"Kühlschrank"]
http://192.168.0.75/api/set?dwo=null
http://192.168.0.75/api/set?dwo=3.14
http://192.168.0.75/api/set?bac=false&sdp=true
```

In der HTTP-Antwort sollte für jeden verarbeiteten Api-Key ein Ergebnis im JSON-Objekt sein, true wenn erfolgreich, oder ein string mit der Fehlermeldung.

```
{
  "bac": true,
  "sdp": true
}
```