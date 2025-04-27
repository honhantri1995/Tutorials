Feature: showing off behave

  Scenario: run a simple test
    Given we have behave installed
    When we implement a test
    Then behave will test it for us

  Scenario: run a simple test with parameters
    Given we have behave installed
    When we implement 2 tests
    Then behave will test them for us
    #Color green
    @thisIsATag
