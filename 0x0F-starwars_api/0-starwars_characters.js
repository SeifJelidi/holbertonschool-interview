#!/usr/bin/node
const request = require('request');

request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], async (err, response, body) => {
  if (err) console.log(err);
  for (const c of JSON.parse(body).characters) {
    await new Promise((resolve, reject) => {
      request(c, (e, response, body) => {
        if (e) console.log(err);
        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
