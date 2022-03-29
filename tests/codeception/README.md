## Codeception

### Exec in docker

1. `cp acceptance.suite.dist.yml acceptance.suite.yml`
    - Webdriver config should in acceptance.suite.yml:
        - url: http://apache
        - host: webdriver
        - port: 4444
2. attach to php container
    - `docker exec -it -u apache wn-php /bin/bash`
3. goto test dir
    - `cd tests/codeception/`
4. run
    - `codecept run acceptance --html --steps`
