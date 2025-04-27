from behave import *

@given('we have behave installed')
def step_impl(context):
    pass

@when('we implement a test')
def step_impl(context):
    assert True is not False

@when('we implement {} tests')
def step_impl(context, count: int):
    assert True is not False

@then('behave will test {} for us')
def step_impl(context, noun: str):
    assert True is not False

@when('run cmd {} to {}')
def step_when(context, string, unused='') :
    print(f'run {string}')
    pass

@then('value of did {} is {}')
def step_then(context, did, value) :
    print('expect')

@then('value of did {} is {}')
def step_then(context, did, value) :
    print('expect')

# def before_feature(context):
#     print('before')