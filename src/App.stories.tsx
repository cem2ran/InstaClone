import * as React from "react";
import { storiesOf } from "@storybook/react-native";
import { default as App } from "./App.gen";
import { apolloMocks } from "../.storybook/fixtures";

export default {
  title: "App",
  decorators: [apolloMocks()],
};

export const app = () => <App />;

app.story = {
  name: "to Storybook",
};

storiesOf("App", module).addDecorator(apolloMocks()).add(app.story.name, app);
