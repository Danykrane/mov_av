// отправояемые данные
const postData = querystring.stringify({ 
    'login': 'qwertyuiop',
    'password': '12456',
    'nameSurname': 'Atryom Gudzenko',
    'loginToken': '1234',
  });


Buffer.byteLength(postData); // подсчет кол-ва байт в запросе



const options = {
    hostname: 'https://developer.mozilla.org/ru/',
    path: '/upload',
    method: 'POST',
    headers: {
      'Content-Type': 'application/x-www-form-urlencoded', // тип отправления контента
      'Content-Length': Buffer.byteLength(postData) //длина сообщения
    }
  };
  const req = http.request(options, (res) => {
    console.log(`STATUS: ${res.statusCode}`);
  });
  req.write(postData);
  req.end();