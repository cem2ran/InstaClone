import { getStorybookUI, configure } from '@storybook/react-native'

import React from 'react'
import { NativeModules } from 'react-native'
import url from 'url'

import { loadStories } from './storyLoader'

// import stories
configure(() => {
    loadStories()
}, module)

const { hostname } = url.parse(NativeModules.SourceCode.scriptURL)

const StorybookUIRoot = getStorybookUI({
    port: 7007,
    host: hostname,
    isUIHidden: true,
    shouldDisableKeyboardAvoidingView: true,
})

// react-native hot module loader must take in a Class - https://github.com/facebook/react-native/issues/10991
// https://github.com/storybooks/storybook/issues/2081
// eslint-disable-next-line react/prefer-stateless-function
class StorybookUIHMRRoot extends React.Component {
    render() {
        return <StorybookUIRoot />
    }
}

export default StorybookUIHMRRoot
