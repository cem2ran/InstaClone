import { Platform } from "react-native";

const isWeb = Platform.OS === "web";

//If we're running Expo in Development mode we use Storybook entry, otherwise App.
const App =
  !isWeb && __DEV__
    ? require("./.storybook/config").default
    : require("./src/App.bs").default;

export default App;
