open ReactNavigation;

[@react.component]
let app = () => {
  <Native.NavigationContainer>
    <Config.Apollo.Provider> <Profile /> </Config.Apollo.Provider>
  </Native.NavigationContainer>;
};

[@genType]
let default = app;