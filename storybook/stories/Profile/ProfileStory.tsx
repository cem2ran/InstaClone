import * as React from 'react'
import { storiesOf } from '@storybook/react-native'
import Profile from '../../../src/Profile/Profile.gen'
import { apolloMocks } from '../../fixtures'

import { NavigationNativeContainer } from '@react-navigation/native';

export const navigationDecorator = (
    storyFn,
) => <NavigationNativeContainer>{storyFn()}</NavigationNativeContainer>;

storiesOf('Profile', module)
    .addDecorator(navigationDecorator)
    .addDecorator(apolloMocks())
    .add('Profile', () => <Profile />)
