The implementation for above Abstract Factory will look like this:

// Include required headers
class NYPizzaIngredientFactory : public PizzaIngredientFactory
{
public:
   NYPizzaIngredientFactory() {
     // Initialize member variables
   }
   ~NYPizzaIngredientFactory() {
     // Empty
     // The factory DON’T delete its products; it’s the responsibility of the Pizza below
   }

   Dough* createDough() {
      return new ThinCrustDough();
   }

   Sauce* createSauce() {
      return new MarinaraSauce();
   }
};

// Include required headers
class Pizza
{
public:
   Pizza() {
      // Initialize all member variables
   }
   ~Pizza() {
      // Delete object pointed by mFactory, mDough and mSauce
   }
   void createPizza(PIZZA inType) {
      if(inType == NY) {
         mFactory = new NYPizzaIngredientFactory();
      } else if(inType == CHICAGO) {
         mFactory = new ChicagoPizzaIngredientFactory();
      }

      mDough = mFactory->createDough();
      mSauce = mFactory->createSauce();
   }

private:
   PizzaIngredientFactory* mFactory;
   Dough* mDough;
   Sauce* mSauce;
}

int main()
{
   // Create a New York-styled pizza
   Pizza pizza;
   pizza.createPizza(NY);
   // …
   return 0;
}
