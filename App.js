//If we're running Expo in Development mode we use Storybook entry, otherwise App.
const App = __DEV__
    ? require('./storybook').default
    : require('./src/App.bs').default

export default App