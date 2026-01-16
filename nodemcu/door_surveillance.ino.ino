void handleRoot() {
  String page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Smart Door Dashboard</title>

<style>
body {
  margin:0;
  font-family: Arial, sans-serif;
  background: linear-gradient(135deg, #020617, #0f172a);
  color: white;
}
.container {
  max-width: 900px;
  margin: auto;
  padding: 20px;
}
h1 {
  text-align: center;
  margin-bottom: 25px;
}
.grid {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(220px, 1fr));
  gap: 15px;
}
.card {
  background: rgba(255,255,255,0.08);
  border-radius: 16px;
  padding: 20px;
  box-shadow: 0 0 20px rgba(0,0,0,0.4);
}
.card h2 {
  font-size: 18px;
  margin-bottom: 10px;
}
.value {
  font-size: 28px;
  font-weight: bold;
}
.alert {
  color: #f87171;
  font-weight: bold;
}
.safe {
  color: #4ade80;
}
.buttons {
  display: flex;
  gap: 15px;
  margin-top: 25px;
}
button {
  flex:1;
  padding: 15px;
  font-size: 18px;
  border-radius: 14px;
  border: none;
  cursor: pointer;
}
.open { background:#22c55e; }
.close { background:#ef4444; }
button:hover { opacity:0.85; }
.footer {
  margin-top: 25px;
  text-align: center;
  opacity: 0.6;
}
</style>

<script>
setTimeout(() => { location.reload(); }, 2000);
</script>

</head>

<body>
<div class="container">
<h1>🚪 Smart Door Control Panel</h1>

<div class="grid">

<div class="card">
<h2>Door Status</h2>
<div class="value">)rawliteral";

  page += doorOpen ? "OPEN" : "CLOSED";

  page += R"rawliteral(</div>
</div>

<div class="card">
<h2>Distance</h2>
<div class="value">)rawliteral";

  page += String(distanceCM) + " cm";

  page += R"rawliteral(</div>)rawliteral";

  if(distanceCM>0 && distanceCM<PERSON_DISTANCE)
    page += "<div class='alert'>Person Near Door</div>";
  else
    page += "<div class='safe'>No One Nearby</div>";

  page += R"rawliteral(
</div>

<div class="card">
<h2>Air Quality (AQI)</h2>
<div class="value">)rawliteral";

  page += String(gasValue);

  page += R"rawliteral(</div>)rawliteral";

  if(gasValue>AQI_LIMIT)
    page += "<div class='alert'>Purifier ON</div>";
  else
    page += "<div class='safe'>Air Normal</div>";

  page += R"rawliteral(
</div>

<div class="card">
<h2>Security Status</h2>)rawliteral";

  if(collisionActive)
    page += "<div class='alert'>COLLISION DETECTED</div>";
  else
    page += "<div class='safe'>All Safe</div>";

  page += R"rawliteral(
</div>

</div>

<div class="buttons">
<button class="open" onclick="location.href='/open'">OPEN DOOR</button>
<button class="close" onclick="location.href='/close'">CLOSE DOOR</button>
</div>

<div class="footer">
Smart IoT Door System • NodeMCU ESP8266
</div>

</div>
</body>
</html>
)rawliteral";

  server.send(200, "text/html", page);
}
