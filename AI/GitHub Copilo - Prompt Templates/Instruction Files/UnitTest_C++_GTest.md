# Unit test coding guideline
## Framework
- GoogleTest (gtest) latest version

## Code quality
- Branch coverage must be 100%.
- Function coverage must be 100%
- Line coverage must be 100%.
- Tests must be independent and repeatable.
- A test must only verify one thing. The bug will likely break only one or two tests instead of dozens.

## Naming convention
- Name test using this template: TEST_F(<class-name>, <function-name>_<test-id>) where <class-name> is the name of the class (e.g. JsonParser), <function-name> is the name of the method without including arguments (e.g. ReadFile), <test-id> is the ID of the test and it's increased by 1 (e.g. the first test has test ID as TC001, the second test has test ID as TC002, etc.). For example:
	```cpp
		// If production code is
		int GetTimeOut(int time);

		// Them unit test code must be
		TEST_F(MockFoo, GetTimeOut_TC001) { ... }
		TEST_F(MockFoo, GetTimeOut_TC002) { ... }
	```

## Mocking with gMock
- All functions/methods must be mocked using gmock, excepts for class constructor and destructor.
- All MOCK_METHOD must be public, regardless of the method being mocked being public, protected, or private in the base class.
- Don't mock methods of classes from in the production code that tests don't call them.
- General syntax for mock classes:
	+ Mock classes are defined as normal classes, using the MOCK_METHOD macro to generate mocked methods. The macro gets 3 or 4 parameters:
		```cpp
			class MyMock {
				public:
					MOCK_METHOD(ReturnType, MethodName, (Args...));
					MOCK_METHOD(ReturnType, MethodName, (Args...), (Specs...));
			};
		```
	+ The first 3 parameters are the method declaration, split into 3 parts.
	+ The 4th parameter accepts a comma-separated list of qualifiers, which affect the generated method:
		+ `const` - Makes the mocked method a const method. Required if overriding a const method.
		+ `override` - Marks the method with override. Recommended if overriding a virtual method.
		+ `noexcept` - Marks the method with noexcept. Required if overriding a noexcept method.
		+ `Calltype(...)` - Sets the call type for the method (e.g. to STDMETHODCALLTYPE), useful in Windows.
		+ `ref(...)` - Marks the method with the reference qualification specified. Required if overriding a method that has reference qualifications. Eg ref(&) or ref(&&)
- Example of mocking normal class:
	```cpp
		class Foo {
			public:
				virtual bool Transform(Gadget* g) = 0;
			protected:
				virtual void Resume();
			private:
				int GetTimeOut(int time);
				const Bar& GetBar() const;
				bool CheckMap(std::map<int, double> map, bool b);
		};

		class MockFoo : public Foo {
			public:
				MOCK_METHOD(bool, Transform, (Gadget* g), (override));
				MOCK_METHOD(void, Resume, (), (override));
				MOCK_METHOD(int, GetTimeOut, (int time), ());
				MOCK_METHOD(const Bar&, GetBar, (), (const));
				MOCK_METHOD(bool, CheckMap, ((std::map<int, double>), bool));
		};
	```
- Example of mocking class template:
	```cpp
		template <typename Elem>
		class StackInterface {
			virtual ~StackInterface();

			virtual int GetSize() const = 0;
			virtual void Push(const Elem& x) = 0;
		};

		template <typename Elem>
		class MockStackInterface : public StackInterface<Elem> {
			MOCK_METHOD(int, GetSize, (), (override));
			MOCK_METHOD(void, Push, (const Elem& x), (override));
		};
	```

## Test script
- Use test fixture. That's mean use TEST_F() instead of TEST().
- There must be Setup() and Teardown() for each test fixture.
- There must be at least 3 tests for each method of the production code.
- Always use non-fatal assertion (e.g. EXPECT_EQ, EXPECT_TRUE, etc.) instead of fatal assertion (e.g. ASSERT_EQ, ASSERT_TRUE, etc.).
- There must be at most 2 assertions (e.g. EXPECT_EQ, EXPECT_TRUE, etc.) for each method of the production code.
- To call mocked method, use EXPECT_CALL if return value of the method is checked. Othewise, use ON_CALL.
- Prevent Uninteresting Call (mock methods, having no EXPECT_CALL but called).

## Comment guideline
- For each test, add a top comment containing the method name and a brief of what test covers:
	```cpp
		// GetTimeOut - input time is valid
		TEST_F(MockFoo, GetTimeOut_TC001) { ... }

		// GetTimeOut - input time is invalid
		TEST_F(MockFoo, GetTimeOut_TC002) { ... }

		// Transform - input pointer is valid
		TEST_F(MockFoo, Transform_TC001) { ... }

		// Transform - input pointer is null
		TEST_F(MockFoo, Transform_TC001) { ... }
	```

## Test example
### Production code
### Unit test code
#### Mock file
#### Test script
