import * as React from "react";
import { storiesOf } from "@storybook/react-native";
import Profile from "./Profile.gen";
import Posts from "./components/Posts.gen";
import { navigationDecorator, apolloMocks } from "../../.storybook/fixtures";

const title = "Profile";

export default { title, decorators: [navigationDecorator, apolloMocks()] };

export const profile = () => <Profile />;
export const posts = () => (
  // @ts-ignore
  <Posts navigateToPost={(id) => console.log("navigateToPost", id)} />
);

storiesOf(title, module)
  .addDecorator(navigationDecorator)
  .addDecorator(apolloMocks())
  .add("Profile", profile)
  .add("Posts", posts);
