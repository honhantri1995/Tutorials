class Singleton {
public:
   static Singleton* getInstance() {
      if (mInstance == NULL) {
         mInstance = new Singleton();
      }
      return mInstance;
   }

   static void releaseInstance() {
      if (mInstance != NULL) {
         delete mInstance;
         mInstance = NULL;
      }
   }

   void func() { … }

private:
   static Singleton* mInstance;	// Unique point of access
   Singleton() {}			// Prevent clients from creating a new Singleton
   ~Singleton() {}			// and also from deleting the old object
};

Singleton* Singleton::mInstance = NULL;

int main() {
   ...
   Singleton* singleton = Singleton::getInstance();	// The only way to get object
   singleton->func();
   ...
   Singleton::releaseInstance();				// Maybe in another file
   return 0;
}
