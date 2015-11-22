
mongo test --eval "db.dropDatabase()"
mongoimport --db test --collection scotishCities --drop --file ScotishCities60.json
