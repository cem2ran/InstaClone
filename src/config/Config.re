module Apollo = {
  let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

  let httpLink =
    ApolloLinks.createHttpLink(~uri="http://localhost:3000/graphql", ());

  let instance =
    ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());

  module Provider = {
    [@react.component]
    let make = (~apollo as client=instance, ~children) =>
      <ReasonApollo.Provider client>
        <ReasonApolloHooks.ApolloProvider client>
          children
        </ReasonApolloHooks.ApolloProvider>
      </ReasonApollo.Provider>;
  };
};